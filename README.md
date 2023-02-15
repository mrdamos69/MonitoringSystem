# Monitoring System

Implementation of the monitoring system project.

## Information

**Monitoring systems** are maintenance systems for continuous surveillance. In a software environment, such a system is a metasystem, i.e. a superstructure over some system that describes it. Monitoring software systems involves *logging* and collecting specific *metrics*. Metrics tell you how much of something there is, like how much memory is available in the computer system or how many centimeters long is the desk. This is a fundamental property of the metric - its computability. In our case, the metrics collected by the monitoring system relate to the program, software package and/or environment that is being monitored. \
The *critical values* of a metric are the area of the number line of metric values, at which the system should send a notification to the system administrator.

This is obviously a very useful addition, allowing the sysadmin to be automatically notified of critical metric values, without having to look at them all day long.
This could be, for example, notification about 95% fullness of the hard disk, which means that the administrator should clean the computer.

In this work, you won't have to monitor the status of any special software package, but instead you will have to monitor the status of specific metrics of your operating system. \
*Logging* means recording the *logs* or *log entries* of the executable software into a separate text file.
These can be the debug lines you are already familiar with, as well as messages about errors occurring during the program's execution or about the passage of its key stages. In our case, the operating system logs won’t be monitored.

In the vast majority of cases of existing software (*Zabbix*, *Grafana*, *Nagios*, etc.), the monitoring system is a kernel that collects the actual values of metrics (usually in a special non-relational database) and agent programs that collect specific metrics (usually they are logically separated, for example, an agent working with CPU metrics, or an agent working with accumulator metrics, etc.). Agents are lightweight programs that run in the background and collect actual metrics values at a time interval specified in a configuration file. \

As an agent, we suggest using dynamic libraries (*.so), for example, with the `updateMetrics()` method, which allows loading the actual metrics values collected by this agent-library. It is important that not only could there be an arbitrary number of agents, but they could also be dynamically connected/disconnected while the monitoring system kernel is running.
For example, by loading new agents into some `./agents/` directory. Instead of a database with metrics it is suggested to use a single log-file for the whole monitoring system, in which a list with actual metrics values is written periodically at the time specified in the configuration file in the following form:

```
[<TIMESTAMP>] | <Metric1> : <Value1> |  <Metric2> : <Value2> |  <Metric3> : <Value3> | ...

```

- \<TIMESTAMP\> - timestamp in the format `yy-M-M-dd HH:mm:ss`

- \<MetricN\> - Nth metric

- \<ValueN\> - value of the Nth metric


## Part 1. Implementation of a monitoring system

- The program must be developed in C++ language of C++17 standard 
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests. Installation directory could be arbitrary, except the building one
- Classes must be implemented within the `s21` namespace
- Prepare full coverage of modules that implement the business logic of the application with unit-tests using the GTest library
- GUI implementation, based on any GUI library with API for C++17: Qt, SFML, GTK+, Nanogui, Nngui, etc.
- The program must be implemented using the MVC pattern, and also:
     - there should be no business code in the view code
     - there should be no interface code in the controller and the model
     - controllers must be thin
- The program must consist of a kernel and agents. The kernel must periodically call the appropriate methods of the agents connected to it (dynamic libraries in the folder `./agents/`) and record actual metrics as a list in the monitoring system log in the folder `./logs/`.
- A separate log file is created for each day of the monitoring system operation. The log file must be named with the full date of the day it was created.
- The kernel program in a **separate thread** should scan the `./agents/` folder at specified intervals of a few seconds for *new* agents that should be connected to the system and displayed in the interface.
- New agents must be built via a separate makefile, agent configuration must be done via the configuration file attached to the agent code. During initialization, the agent must read the actual configuration file and save the settings until the end of the program execution or until they are changed by the user.
- The configuration file must provide the ability to change:
    - agent name
    - agent type
    - list of critical metrics values
    - metrics update time
- At least three different types of agents must be provided:
    - The CPU load monitoring agent must be able to collect the following metrics:
        - `[double]` CPU load (`cpu`)
        - `[int]` number of processes (`processes`)
    - The memory monitoring agent must be able to collect the following metrics:
        - `[double]` total amount of RAM (`ram_total`)
        - `[double]` load of RAM in percent (`ram`),
        - `[double]` usage of hard disk volume (`hard_volume`),
        - `[int]` number of I/O operations for the hard disk per second (`hard_ops`)
        - `[double]` hard disk throughput (`hard_throughput `)
    - The network monitoring agent must be able to collect the following metrics:
        - `[int : 0 -> not available, 1 -> available]` address availability (`<url>`)
        - `[double]` throughput of used network interfaces (`inet_throughput`)
- In the configuration file the metrics are specified by name in Latin (`cpu`, `ram`, `hard_volume`, `hard_ops`, `hard_throughput`, `processors`, `processes`) or via url for address availability metric. It should be possible to specify a critical value for each metric through the equality/non-equality symbol and the number. For example: >=2, ==100, <50, etc.
- The program interface must display:
    - the last 20 lines of the log, the log window must be dynamically updated each time a log entry is made
    - list of connected agents
- The program interface must allow:
    - getting detailed information about the agent:
        - agent type 
        - list of monitored metrics
        - time elapsed since agent's start
        - metrics update time
    - dynamically changing the configuration of an already running agent (with saving it to a configuration file)
    - disconnecting the agent selected in the list

## Part 2. Notifications

- To send a notification to the system administrator about a critical situation, a simple *Telegram* bot must be developed that sends a message when the metric reaches its critical value. The message must contain the name of the computer (host), the name of the metric and its value.
- Provide the ability to enable/disable duplication of notifications to the specified *email address* in the interface.
- It is allowed to use *any* external С++ libraries working with Telegram and emails to implement the logic of sending messages to Telegram and email.

## Part 3. Bonus. Implementation of an agent with special metrics.

Implement at least one more agent collecting additional metrics:

- `[double]` CPU load by privilege level: `idle`, `user`, `priveleged`, `dpc`, `interrupt` (output percentage for each level) (`cpu_idle_usage`, `cpu_user_usage`, ...)
- `[double]` total swap volume (`total_swap`)
- `[double]` amount of swap used (`used_swap`) 
- `[int]` number of processes ready to run in the queue (read about process states in *Unix* if necessary) (`proc_queue_length`)
- `[double]` counting full and free virtual memory (`virtual_mem_volume`, `virtual_mem_free`)
- `[int]` total number of inodes (`inodes`)
- `[double]` average hard disk read time (`hard_read_time`)
- `[int]` number of errors from the system log (`system_errors`)
- `[int]` number of user authorizations (`user_auths`)

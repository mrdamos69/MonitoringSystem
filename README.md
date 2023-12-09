# Monitoring System Project

## Overview

The **Monitoring System project** is designed to provide continuous surveillance of an operating system by monitoring specific metrics. The system consists of a kernel and dynamically connectable agents, implemented as dynamic libraries. The project is written in C++17 following the Google style guide and employs the Model-View-Controller (MVC) pattern.

## Features

### 1. Monitoring System Implementation

- **Language:** C++17
- **Directory Structure:**
  - `src`: Contains the program code.
  - `agents`: Dynamic libraries (agents) are stored here.
  - `logs`: Log files are stored here, each named with the full date of its creation.
- **Build System:** Makefile with standard GNU targets (all, install, uninstall, clean, dvi, dist, tests).
- **Namespace:** The program code is organized within the `s21` namespace.
- **Unit Tests:** Full coverage of modules with unit tests using the GTest library.
- **GUI:** Implementation based on any GUI library with C++17 API (e.g., Qt, SFML, GTK+).
- **MVC Pattern:**
  - Business logic is separated into the model.
  - No business code in the view.
  - No interface code in the controller and model.
  - Controllers are thin.

### 2. Agents

- **Dynamic Connection/Disconnection:** Agents can be dynamically connected/disconnected while the monitoring system kernel is running.
- **Agent Types:**
  - CPU Load Monitoring Agent
  - Memory Monitoring Agent
  - Network Monitoring Agent
- **Agent Configuration:**
  - Agent name
  - Agent type
  - List of critical metric values
  - Metrics update time

### 3. Logging

- Metrics are logged in a specified format with a timestamp.
- Separate log file for each day of system operation.

### 4. User Interface

- Display the last 20 lines of the log with dynamic updates.
- List of connected agents.
- Detailed information about agents:
  - Agent type
  - Monitored metrics
  - Time elapsed since agent's start
  - Metrics update time
- Dynamic configuration changes for running agents with saving to a configuration file.
- Disconnecting selected agents.

### 5. Notifications

- Simple Telegram bot for sending messages on critical metric values.
- Enable/disable duplication of notifications to a specified email address.

## Part 3 Bonus Features

### Additional Agent Metrics

Implement at least one more agent collecting the following additional metrics:

- CPU load by privilege level
- Total swap volume
- Amount of swap used
- Number of processes ready to run in the queue
- Counting full and free virtual memory
- Total number of inodes
- Average hard disk read time
- Number of errors from the system log
- Number of user authorizations

## Implementation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/mrdamos69/MonitoringSystem.git
   cd MonitoringSystem

2. **Build the project:**
    ```bash
    make install

## Contributors
[Dmitrii Chichkanov (mrdamos69)](https://github.com/mrdamos69)

[Ayzat Akhmetzyanov (AjzSAhmetzyanov)](https://github.com/AjzSAhmetzyanov)

[Aydin Shamil (DonOutcast)](https://github.com/DonOutcast)
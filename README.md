# System metrics monitor

A C++17 and Qt desktop project for inspecting CPU, memory and network-related measurements. It combines a graphical interface, worker threads and text-based logging.

The engineering focus is separation between metric collection, orchestration and presentation. The monitoring agents here are system-metric collectors, not LLM agents.

## Code walkthrough

| Area | What to inspect |
|---|---|
| [Metric collectors](model/agents/) | CPU, memory, network and additional system measurements |
| [Worker startup](model/utilitys/lib_start_agent.cc) | Thread-based collector execution |
| [Model](model/model.h) | Entry points for monitoring operations |
| [Controller](controller/) | Interface between the model and Qt view |
| [Qt interface](view_monitoring_system/) | Controls, configuration and log presentation |
| [Tests](unit_test/unit_test.cc) | Existing GoogleTest cases |

## Build

The Qt project is [view_monitoring_system.pro](view_monitoring_system/view_monitoring_system.pro). Open it in Qt Creator with a C++17-capable desktop kit.

The existing Makefile also provides:

```bash
make install
make test
```

The install target expects a macOS `.app` bundle and qmake on PATH. GoogleTest is required for the test target. Metric collectors rely on operating-system commands, so portability needs to be checked for the target OS.

## Scope

This is an earlier engineering project, not a production monitoring service. Collectors are compiled into the application; the published code should not be described as a verified dynamic-plugin platform. Existing tests are included, but no complete coverage figure is claimed.

Before using it outside a local development environment, review shell-command construction, configuration handling and notification settings. Do not put credentials or personal data into public configuration or logs.

## Contributors

- [Dmitrii Chichkanov](https://github.com/mrdamos69)
- [Ayzat Akhmetzyanov](https://github.com/AjzSAhmetzyanov)
- [Aydin Shamil](https://github.com/DonOutcast)

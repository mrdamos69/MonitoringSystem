#include "utils.h"
#include <array>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>
#include <mutex>
#include <regex>
#include <string>
#include <thread>
#include <vector>

double ram_total() {
  std::string command =
      "system_profiler SPHardwareDataType | grep \"Memory\" | awk '{print $2}'";
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  return std::stod(output);
}

double ram() {
  std::string command =
      "ps -caxm -orss= | awk '{ sum += $1 } END { print sum/1024/1024 }'";
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  return std::stod(output);
}

double hard_volume() {
  std::string command =
      "df -H | awk '{ sum = /\\/dev\\/disk3/ } END {print $3}' | cut -c 1-3";
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  return std::stod(output);
}

double hard_ops() {
  std::string command = "iostat -c 1 -w 10 disk0 | awk '{print $1}'| tail -1";
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  return std::stod(output);
}

double hard_throughput() {
  std::string command = "iostat -c 1 -w 10 disk3 | awk '{print $1}'| tail -1";
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  return std::stod(output);
}

void starting_memory_agent(bool check) {
  std::string result = "";
  if (check) {
    double ram_total_ = ram_total();
    double ram_ = ram();
    double hard_volume_ = hard_volume();
    double hard_ops_ = hard_ops();
    double hard_throughput_ = hard_throughput();
    result = get_time() + " | " + "ram_total" + " : " +
             std::to_string(ram_total_) + " | " + "ram" + " : " +
             std::to_string(ram_) + " | " + "hard_volume" + " : " +
             std::to_string(hard_volume_) + " | " + "hard_ops" + " : " +
             std::to_string(hard_ops_) + " | " + "hard_throughput" + " : " +
             std::to_string(hard_throughput_);
  }
  input_file(result);
}

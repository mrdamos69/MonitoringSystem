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

double cpu_load() {
  std::string command =
      "top -l 1 | grep -E \"^CPU\" | awk '{print $3}' | cut -c 1-4";
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

int number_of_processes() {
  std::string command = "ps -e | wc -l | cut -c 6-8";
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

void starting_cpu_agent(bool check) {
  std::string result;
  if (check) {
    double cpu_usage = cpu_load();
    int processes = number_of_processes();
    result = get_time() + " | " + "cpu" + " : " + std::to_string(cpu_usage) +
             " | " + "processes" + " : " + std::to_string(processes);
  }
  input_file(result);
}

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

std::string validation_url(std::string url) {
  std::string command =
      "curl -I " + url + " -o /dev/null -s -w '%{http_code}\n'";
  int status = std::system(command.c_str());
  return (status == 0 ? "available" : " not available");
}

double speed_network() {
  std::string s1 = "netstat -bI en0 | grep -E \"en0|Bytes\" | grep -v \"Refs\" "
                   "| awk '{print $7}' | tail -1";
  std::string command = s1;
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
  return std::stod(output) / 1024 / 1024 / 1024;
}

void starting_network_agent(std::string url, bool check) {
  std::string result;
  if (check) {
    double speed_network_ = speed_network();
    // std::cout << speed_network_ << std::endl;
    std::string url_ = validation_url(url);
    result = get_time() + " | " + url + " : " + url_ + " | " +
             "inet_throughput" + " : " + std::to_string(speed_network_);
  }
  input_file(result);
}

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <cstdio>
#include <regex>
#include <vector>
#include <fstream>
#include <math.h>
#include <array>
#include <thread>
#include <chrono>
#include "../lib_agents.h"

using std::vector;
using std::string;

namespace s21 {
class Model {
 public:
  Model() {};
  std::vector<double> starting_cpu_agent(bool check);
  std::vector<double> starting_memory_agent(bool check);
  std::pair<bool, double> starting_network_agent(std::string url, bool check);

  void starting_agents(bool cpu, bool memory, bool network, std::string url);

 private:
  double cpu_load();
  int number_of_processes();
  double ram_total();
  double ram();
  double hard_volume();
  double hard_ops();
  double hard_throughput();
  bool validation_url(std::string url);
  double speed_network();
};
}  // namespace s21

#endif

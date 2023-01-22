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

using std::vector;
using std::string;

namespace s21 {
class Model {
 public:
  Model() {};
  std::vector<double> starting_cpu_agent(bool check);

  void download_file_with_marks_memory();

  vector<double> starting_memory_agent(bool check);

  std::pair<bool, double> starting_network_agent(std::string url, bool check);

  void uploading_data_to_file(const std::vector<double>& data1,
                              const std::vector<double>& data2,
                              std::pair<bool, double> config);

  bool validation_url(std::string url);

  double speed_network();

  void starting_agents(bool cpu, bool memory, bool network, std::string url);

};
}  // namespace s21

#endif

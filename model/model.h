#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <array>

using std::vector;
using std::string;

namespace s21 {
class Model {
 public:
  Model() {};
  std::vector<double> starting_cpu_agent();

  void download_file_with_marks_memory();

  vector<double> starting_memory_agent();

  std::pair<bool, double> starting_network_agent(std::string url);

  // void uploading_data_to_file(double cpu, int processes,
  //                             double ram_total, double ram,
  //                             double hard_volume, int hard_ops,
  //                             double hard_throughput,
  //                             bool network_url,
  //                             double doubleinet_throughput);

  bool validation_url(std::string url);

  double speed_network();

};
}  // namespace s21

#endif

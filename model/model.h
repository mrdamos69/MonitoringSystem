#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

namespace s21 {
class Model {
 public:
  Model() {};
  std::pair<double, int> starting_cpu_agent();

  vector<double> starting_memory_agent();

  std::pair<bool, double> starting_network();

  void uploading_data_to_file(double cpu, int processes,
                              double ram_total, double ram,
                              double hard_volume, int hard_ops,
                              double hard_throughput,
                              bool network_url,
                              double doubleinet_throughput);

};
}  // namespace s21

#endif

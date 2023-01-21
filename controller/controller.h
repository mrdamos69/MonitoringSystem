#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
 private:
  s21::Model model;

 public:
  vector<double> starting_cpu_agent(bool check);

  vector<double> starting_memory_agent(bool check);

  std::pair<bool, double> starting_network_agent(std::string url, bool check);

//   void uploading_data_to_file(double cpu, int processes,
//                               double ram_total, double ram,
//                               double hard_volume, int hard_ops,
//                               double hard_throughput,
//                               bool network_url,
//                               double doubleinet_throughput);

};

}  //  namespace s21

#endif

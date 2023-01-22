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

  void uploading_data_to_file(const std::vector<double>& data1,
                              const std::vector<double>& data2,
                              std::pair<bool, double> configt);

};

}  //  namespace s21

#endif

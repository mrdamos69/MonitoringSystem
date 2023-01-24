#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
 private:
  s21::Model model;

 public:
  std::vector<std::string> starting_cpu_agent(bool check);
  std::vector<std::string> starting_memory_agent(bool check);
  std::vector<std::string> starting_network_agent(std::string url, bool check);
  std::vector<std::string> starting_special_agent(std::string lvl_privilege, bool check);

  std::vector<int> load_value_from_config();

};

}  //  namespace s21

#endif

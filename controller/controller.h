#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {
class Controller {
private:
  s21::Model model;

public:
  void starting_cpu_agent();
  void starting_memory_agent();
  void starting_network_agent(std::string &url);
  void starting_special_agent(std::string &lvl_privilege);

  void starting_agents_thread(std::string &lvl_privilege, std::string &url,
                              int &time);
  void starting_project();                            
};

} //  namespace s21

#endif

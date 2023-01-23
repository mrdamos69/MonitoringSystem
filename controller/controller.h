#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
 private:
  s21::Model model;

 public:
  void starting_cpu_agent(bool check);

  void starting_memory_agent(bool check);

  void starting_network_agent(std::string url, bool check);

};

}  //  namespace s21

#endif

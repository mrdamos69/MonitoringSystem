#include "controller.h"

std::vector<std::string> s21::Controller::starting_cpu_agent() {
  return model.starting_cpu_agent();
}

std::vector<std::string> s21::Controller::starting_memory_agent() {
  return model.starting_memory_agent();
}

std::vector<std::string> s21::Controller::starting_network_agent(std::string url) {
  return model.starting_network_agent(url);
}

std::vector<std::string> s21::Controller::starting_special_agent(std::string lvl_privilege) {
  return model.starting_special_agent(lvl_privilege);
}

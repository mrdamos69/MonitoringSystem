#include "controller.h"

std::vector<std::string> s21::Controller::starting_cpu_agent(bool check) {
  return model.starting_cpu_agent(check);
}

std::vector<std::string> s21::Controller::starting_memory_agent(bool check) {
  return model.starting_memory_agent(check);
}

std::vector<std::string> s21::Controller::starting_network_agent(std::string url, bool check) {
  return model.starting_network_agent(url, check);
}

std::vector<int> s21::Controller::load_value_from_config() {
  return model.load_value_from_config();
}
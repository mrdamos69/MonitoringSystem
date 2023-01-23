#include "controller.h"

void s21::Controller::starting_cpu_agent(bool check) {
  model.starting_cpu_agent(check);
}

void s21::Controller::starting_memory_agent(bool check) {
  model.starting_memory_agent(check);
}

void s21::Controller::starting_network_agent(std::string url, bool check) {
  model.starting_network_agent(url, check);
}

#include "controller.h"

void s21::Controller::starting_cpu_agent() { model.starting_cpu_agent(); }

void s21::Controller::starting_memory_agent() { model.starting_memory_agent(); }

void s21::Controller::starting_network_agent(std::string &url) {
  model.starting_network_agent(url);
}

void s21::Controller::starting_special_agent(std::string &lvl_privilege) {
  model.starting_special_agent(lvl_privilege);
}

void s21::Controller::starting_agents_thread(std::string &lvl_privilege,
                                             std::string &url, int &time) {
  model.starting_agents_thread(lvl_privilege, url, time);
}

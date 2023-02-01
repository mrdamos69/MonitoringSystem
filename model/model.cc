#include "model.h"

void s21::Model::starting_cpu_agent() { Lib_agent::cpu_agent(); }

void s21::Model::starting_memory_agent() { Lib_agent::memory_agent(); }

void s21::Model::starting_network_agent(std::string &url) {
  Lib_agent::network_agent(url);
}

void s21::Model::starting_special_agent(std::string &lvl_privilege) {
  Lib_agent::special_agent(lvl_privilege);
}

void s21::Model::starting_agents_thread(std::string &lvl_privilege,
                                        std::string &url, int &time) {
  Lib_agent::starting_agents(lvl_privilege, url, time);
}

void s21::Model::start_bot() {
  Lib_agent::starting_bot();
}

std::string s21::Model::print_last_str() {
  return print_last_string();
}
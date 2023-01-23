#include "model.h"

void s21::Model::starting_cpu_agent(bool check) {
  cpu_agent(check);
}

void s21::Model::starting_memory_agent(bool check) {
  memory_agent(check);
}

void s21::Model::starting_network_agent(std::string url, bool check) {
  network_agent(url, check);
}

void s21::Model::starting_agents(bool cpu, bool memory, bool network, std::string url) {
  starting_agents_thread(cpu, memory, network, url);
}

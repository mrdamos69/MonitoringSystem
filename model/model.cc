#include "model.h"

std::vector<std::string> s21::Model::starting_cpu_agent(bool check) {
  return cpu_agent(check);
}

std::vector<std::string> s21::Model::starting_memory_agent(bool check) {
  return memory_agent(check);
}

std::vector<std::string> s21::Model::starting_network_agent(std::string url, bool check) {
  return network_agent(url, check);
}

std::vector<std::string> s21::Model::starting_agents(bool cpu, bool memory, bool network, std::string url) {
  return starting_agents_thread(cpu, memory, network, url);
}

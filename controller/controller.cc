#include "controller.h"

vector<double> s21::Controller::starting_cpu_agent(bool check) {
  return model.starting_cpu_agent(check);
}

vector<double> s21::Controller::starting_memory_agent(bool check) {
  return model.starting_memory_agent(check);
}

std::pair<bool, double> s21::Controller::starting_network_agent(std::string url, bool check) {
  return model.starting_network_agent(url, check);
}

// void s21::Controller::uploading_data_to_file(double cpu, int processes,
//                                         double ram_total, double ram,
//                                         double hard_volume, int hard_ops,
//                                         double hard_throughput, bool network_url,
//                                         double doubleinet_throughput) {
//   return model.uploading_data_to_file(cpu, processes,
//                                       ram_total, ram,
//                                       hard_volume, hard_ops,
//                                       hard_throughput, network_url,
//                                       doubleinet_throughput);
// }
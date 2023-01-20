#include "controller.h"

std::pair<double, int> s21::Controller::starting_cpu_agent() {
  return model.starting_cpu_agent();
}

vector<double> s21::Controller::starting_memory_agent() {
  return model.starting_memory_agent();
}

std::pair<bool, double> s21::Controller::starting_network() {
  return model.starting_network();
}

void s21::Controller::uploading_data_to_file(double cpu, int processes,
                                        double ram_total, double ram,
                                        double hard_volume, int hard_ops,
                                        double hard_throughput, bool network_url,
                                        double doubleinet_throughput) {
  return model.uploading_data_to_file(cpu, processes,
                                      ram_total, ram,
                                      hard_volume, hard_ops,
                                      hard_throughput, network_url,
                                      doubleinet_throughput);
}
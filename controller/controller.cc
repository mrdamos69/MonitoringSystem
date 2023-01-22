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

void s21::Controller::uploading_data_to_file(const std::vector<double>& data1,
                                            const std::vector<double>& data2,
                                            std::pair<bool, double> config) {
  return model.uploading_data_to_file(data1, data2, config);
}
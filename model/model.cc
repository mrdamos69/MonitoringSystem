#include "model.h"


  std::pair<double, int> s21::Model::starting_cpu_agent() {
    double cpu;
    int processes;
    
    return std::pair<double, int> ();
  }

  vector<double> s21::Model::starting_memory_agent() {
    vector<double> mem_metric;
    double ram_total, ram, hard_volume, hard_throughput;
    int hard_ops;
    return mem_metric;
  }

  std::pair<bool, double> s21::Model::starting_network() {
    bool network_url;
    double doubleinet_throughput;
    return std::pair<bool, double> ();
  }

  void s21::Model::uploading_data_to_file(double cpu, int processes,
                                          double ram_total, double ram,
                                          double hard_volume, int hard_ops,
                                          double hard_throughput, bool network_url,
                                          double doubleinet_throughput) {
    
  }
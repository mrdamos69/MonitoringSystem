#include "model.h"

  // std::pair<double, int> s21::Model::starting_cpu_agent() {
  //   double cpu;
  //   int processes;
    
  //   return std::pair<double, int> ();
  // }

  // vector<double> s21::Model::starting_memory_agent() {
  //   vector<double> mem_metric;
  //   double ram_total, ram, hard_volume, hard_throughput;
  //   int hard_ops;
  //   return mem_metric;
  // }

  std::pair<bool, double> s21::Model::starting_network_agent(std::string url) {
    return std::pair<bool, double> (validation_url(url), speed_network());
  }

  // void s21::Model::uploading_data_to_file(double cpu, int processes,
  //                                         double ram_total, double ram,
  //                                         double hard_volume, int hard_ops,
  //                                         double hard_throughput, bool network_url,
  //                                         double doubleinet_throughput) {
    
  // }

  bool s21::Model::validation_url(std::string url) {
    std::string curl = "curl ";
    std::string script = curl + url + " >> temp_file_8.conf";
    std::system(script.data());
    int count = 0;
    std::ifstream temp_file("temp_file_8.conf");
    if (!temp_file.eof()) {
      std::string lineptr;
      while (std::getline(temp_file, lineptr))
        count++;
    }
    temp_file.close();
    std::system("rm temp_file_8.conf");
    return (count > 1 ? true : false);
  }

  double s21::Model::speed_network() {
    std::string script = "speedtest | awk '/Download:/ { print $2 }' >> temp_file_9.conf";
    std::system(script.data());
    std::string lineptr;
    std::ifstream temp_file("temp_file_9.conf");
    if (!temp_file.eof()) {
      std::getline(temp_file, lineptr);
    }
    temp_file.close();
    std::system("rm temp_file_9.conf");
    return atof(lineptr.data());
  }
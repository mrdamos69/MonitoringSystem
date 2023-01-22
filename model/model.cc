#include "model.h"

  std::vector<double> s21::Model::starting_cpu_agent(bool check) {
    return starting_cpu_agent(check);
  }

   double s21::Model::cpu_load() {
    return cpu_load();
  }

  int s21::Model::number_of_processes() {
    return number_of_processes();
  }

  vector<double> s21::Model::starting_memory_agent(bool check) {
    return starting_memory_agent(check);
  }

  double s21::Model::ram_total() {
    return ram_total();
  }

  double s21::Model::ram() {
    return ram();
  }

  double s21::Model::hard_volume() {
    return hard_volume();
  }

  double s21::Model::hard_ops() {
    return hard_ops();
  }

  double s21::Model::hard_throughput() {
    return hard_throughput();
  }

  std::pair<bool, double> s21::Model::starting_network_agent(std::string url, bool check) {
    return starting_network_agent(url, check);
  }

  void s21::Model::uploading_data_to_file(const std::vector<double>& data1,
                                          const std::vector<double>& data2,
                                          std::pair<bool, double> config) {
  uploading_data_to_file(data1, data2, config); 
  }

  bool s21::Model::validation_url(std::string url) {
    return validation_url(url);
  }

  double s21::Model::speed_network() {
    return speed_network();
  }

  void s21::Model::starting_agents(bool cpu, bool memory, bool network, std::string url) {
      std::vector<double> result;
      std::thread thread_1([this, cpu](){
        this->starting_cpu_agent(cpu);
      });

      std::thread thread_2([this, memory](){
        this->starting_memory_agent(memory);
      });

      std::thread thread_3([this, url, network](){
        this->starting_network_agent(url.data(), network);
      });
      thread_1.join();
      thread_2.join();
      thread_3.join();
   }

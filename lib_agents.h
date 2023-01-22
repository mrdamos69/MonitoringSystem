#ifndef LIB_AGENTS_H_
#define LIB_AGENTS_H_
#include <string>
#include <vector>

double cpu_load();
int number_of_processes();
double ram_total();
double ram();
double hard_volume();
double hard_ops();
double hard_throughput();
void uploading_data_to_file(const std::vector<double> &data1,
                            const std::vector<double> &data2,
                            std::pair<bool, double> config);
bool validation_url(std::string url);
double speed_network();
void input_file(std::string text);

void starting_cpu_agent(bool check);
void starting_memory_agent(bool check);
void starting_network_agent(std::string url, bool check);
#endif
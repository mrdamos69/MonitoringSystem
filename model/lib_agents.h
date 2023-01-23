#ifndef LIB_AGENTS_H_
#define LIB_AGENTS_H_
#include "utils.h"
#include <array>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>
#include <mutex>
#include <regex>
#include <string>
#include <thread>
#include <vector>

double cpu_load();
int number_of_processes();
double ram_total();
double ram();
double hard_volume();
double hard_ops();
double hard_throughput();
std::string validation_url(std::string url);
double speed_network();
void input_file(std::string text);

void cpu_agent(bool check);
void memory_agent(bool check);
void network_agent(std::string url, bool check);
void starting_agents_thread(bool cpu, bool memory, bool network, std::string url);
#endif
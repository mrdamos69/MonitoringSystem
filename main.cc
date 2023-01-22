#include "lib_agents.h"
#include <array>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>
#include <regex>
#include <string>
#include <thread>
#include <vector>

void starting_agents(bool cpu, bool memory, bool network, std::string url) {

  std::thread thread_1(starting_cpu_agent, cpu);

  std::thread thread_2(starting_memory_agent, memory);

  std::thread thread_3(starting_network_agent, url, network);

  thread_1.join();
  thread_2.join();
  thread_3.join();
}

int main() {
  std::string url = "https://edu.21-school.ru";
  starting_agents(true, true, true, url);
  return 0;
}

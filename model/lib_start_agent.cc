#include "lib_agents.h"

void starting_agents_thread(bool cpu, bool memory, bool network, std::string url) {

  std::thread thread_1(cpu_agent, cpu);
  std::thread thread_2(memory_agent, memory);
  std::thread thread_3(network_agent, url, network);

  thread_1.join();
  thread_2.join();
  thread_3.join();
}
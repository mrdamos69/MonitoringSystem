#include "lib_agents.h"
std::vector<std::string> result;
std::mutex g_lock;

std::vector<std::string> return_vector(std::vector<std::string> input_) {
  g_lock.lock();
  for (auto i : input_) {
    result.push_back(i);
  }
  g_lock.unlock();
  return result;
}

std::vector<std::string> starting_agents_thread(bool cpu, bool memory,
                                                bool network, std::string url) {
  std::thread thread_1([&cpu]() { return_vector(cpu_agent(cpu)); });

  thread_1.join();

  std::thread thread_2([&memory]() { return_vector(memory_agent(memory)); });

  thread_2.join();

  std::thread thread_3(
      [&network, &url]() { return_vector(network_agent(url, network)); });

  thread_3.join();

  

  return result;
}

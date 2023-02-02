#include "../agents/lib_agents.h"

auto now() { return std::chrono::steady_clock::now(); }

auto awake_time() {
  using std::chrono::operator""ms;
  return now() + std::chrono::seconds(2);
}

void Lib_agent::starting_agents(std::string &lvl_privilege, std::string &url,
                                std::vector<int> &agents) {
  auto start = std::chrono::high_resolution_clock::now();
  auto finish = start + std::chrono::seconds(agents[4]);
  while (std::chrono::high_resolution_clock::now() < finish) {
    std::this_thread::sleep_until(awake_time());
    try {
      if (agents[0] == 1) {
        std::thread thread_1([]() { cpu_agent(); });
        thread_1.join();
      }
      if (agents[1] == 1) {
        std::thread thread_2([]() { memory_agent(); });
        thread_2.join();
      }
      if (agents[2] == 1) {
        std::thread thread_3([&]() { network_agent(url); });
        thread_3.join();
      }
      if (agents[3] == 1) {
        std::thread thread_4([&]() { special_agent(lvl_privilege); });
        thread_4.join();
      }
    } catch (const std::exception &ex) {
      std::cout << "Thread exited with exception: " << ex.what() << "\n";
    }
  }
}

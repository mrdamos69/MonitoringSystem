#include "../agents/lib_agents.h"
// std::mutex g_lock;

auto now() { return std::chrono::steady_clock::now(); }

auto awake_time() {
  using std::chrono::operator""ms;
  return now() + std::chrono::seconds(1);
}

void Lib_agent::starting_agents(std::string lvl_privilege, std::string url,
                                int time) {
  auto start = std::chrono::high_resolution_clock::now();
  auto finish = start + std::chrono::seconds(
                            time); // time это время выполнения этой функции
  auto timer{std::chrono::steady_clock::now()};

  while (std::chrono::high_resolution_clock::now() < finish) {
    std::this_thread::sleep_until(awake_time());
    try {
      std::thread thread_1([&]() { cpu_agent(); });
      thread_1.join();
    } catch (const std::exception &ex) {
      std::cout << "Thread_1 exited with exception: " << ex.what()
                << "\n";
    }
    try {
      std::thread thread_2([&]() { memory_agent(); });
      thread_2.join();
    } catch (const std::exception &ex) {
      std::cout << "Thread_2 exited with exception: " << ex.what()
                << "\n";
    }
    try {
      std::thread thread_3([&]() { network_agent(url); });
      thread_3.join();
    } catch (const std::exception &ex) {
      std::cout << "Thread_3 exited with exception: " << ex.what()
                << "\n";
    }
    try {
      std::thread thread_4([&]() { special_agent(lvl_privilege); });
      thread_4.join();
    } catch (const std::exception &ex) {
      std::cout << "Thread_4 exited with exception: " << ex.what()
                << "\n";
    }
  }
}

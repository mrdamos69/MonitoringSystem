#include <gtest/gtest.h>

#include "../model/model.h"

TEST(Test_Monitoring_system, test_cpu_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_cpu_agent();
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_memory_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_memory_agent();
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_network_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_network_agent("https://edu.21-school.ru");
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_special_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_special_agent("cpu_idle_usage");
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_load_config) {
  std::vector<int> result = get_metric_from_file();
  ASSERT_TRUE(!result.empty());
}

TEST(Test_Monitoring_system, test_starting_agents) {
  s21::Model model; 
  std::vector<std::string> result;
  result = model.starting_agents_thread("cpu_idle_usage", "https://edu.21-school.ru");
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

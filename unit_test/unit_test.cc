#include <gtest/gtest.h>

#include "../model/model.h"

TEST(Test_Monitoring_system, test_cpu_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_cpu_agent(true);
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_memory_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_memory_agent(true);
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_network_agent) {
  s21::Model model;
  std::vector<std::string> result = model.starting_network_agent("https://edu.21-school.ru", true);
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_starting_agents) {
  s21::Model model; 
  std::vector<std::string> result;
  result = model.starting_agents(1, 1, 1, "https://edu.21-school.ru");
  for (auto i : result) {
    ASSERT_TRUE(!i.empty());
  }
}

TEST(Test_Monitoring_system, test_load_config) {
  s21::Model model;
  std::vector<int> result = model.load_value_from_config();
  ASSERT_TRUE(!result.empty());
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

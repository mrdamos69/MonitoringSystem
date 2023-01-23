#include <gtest/gtest.h>

#include "../model/model.h"

// TEST(Test_Monitoring_system, test_check_url) {
//   s21::Model model;
//   std::pair<bool, double> result;
//   result = model.starting_network_agent("https://edu.21-school.ru", true);
//   ASSERT_TRUE(result.first && result.second > 0);
// }

TEST(Test_Monitoring_system, test_starting_agents) {
  s21::Model model;
  model.starting_agents(1, 0, 1, "https://edu.21-school.ru");
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

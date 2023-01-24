#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include "../agents/lib_agents.h"

std::vector<std::string> load_value_from_config() {
  std::ifstream file("config.conf");
  std::string str;
  std::vector<std::string> lines;

  while (std::getline(file, str)) {
    lines.push_back(str);
  }
  return lines;
}

std::vector<int> get_metric_from_file() {
  std::vector<std::string> lines = load_value_from_config();
  std::string temp = "";
  std::vector<int> result;

  for (auto i = 4; i < 31; i++) {
    std::string vector_res = lines[i];
    auto found = vector_res.find_first_of("0123456789");

    if (found != std::string::npos) {
      for (auto j = found; isdigit(vector_res[j]); j++) {
        temp += vector_res[j];
      }
      result.push_back(stoi(temp));
      temp.clear();
    }
  }
  return result;
}
// #include <fstream>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <typeinfo>
#include "model.h"

std::vector<int> s21::Model::load_value_from_config() {
  std::ifstream file("config.conf");
  std::string str;

  std::vector<std::string> lines;
  std::vector<int> result;
  while (std::getline(file, str)) {
    lines.push_back(str);
  }
//   // get_name_agents
//   result.push_back(stoi(lines[0]));
//   result.push_back(stoi(lines[1]));
//   result.push_back(stoi(lines[2]));
//   result.push_back(stoi(lines[3]));

  // get_type_agents
  result.push_back(stoi(lines[5].substr(14, 3)));
  result.push_back(stoi(lines[6].substr(16, 3)));
  result.push_back(stoi(lines[7].substr(17, 3)));
  result.push_back(stoi(lines[8].substr(16, 3)));

  // get_critical_metrics
  result.push_back(stoi(lines[10].substr(7, 3)));
  result.push_back(stoi(lines[11].substr(13, 3)));
  result.push_back(stoi(lines[12].substr(13, 3)));
  result.push_back(stoi(lines[13].substr(7, 3)));
  result.push_back(stoi(lines[14].substr(15, 3)));
  result.push_back(stoi(lines[15].substr(12, 3)));
  result.push_back(stoi(lines[16].substr(19, 3)));
  result.push_back(stoi(lines[17].substr(19, 3)));
  result.push_back(stoi(lines[18].substr(8, 3)));
  result.push_back(stoi(lines[19].substr(8, 3)));
  result.push_back(stoi(lines[20].substr(14, 3)));
  result.push_back(stoi(lines[21].substr(7, 3)));
  result.push_back(stoi(lines[22].substr(13, 3)));
  result.push_back(stoi(lines[23].substr(14, 3)));
  result.push_back(stoi(lines[24].substr(13, 3)));
  result.push_back(stoi(lines[25].substr(21, 3)));
  result.push_back(stoi(lines[26].substr(22, 3)));
  result.push_back(stoi(lines[27].substr(20, 3)));
  result.push_back(stoi(lines[28].substr(10, 3)));
  result.push_back(stoi(lines[30].substr(17, 3)));
  result.push_back(stoi(lines[31].substr(14, 3)));

  // get_time
  result.push_back(stoi(lines[33].substr(8, 2)));

  // for (auto i : result) {
  //     std::cout << i << std::endl;
  // }
  return result;
}
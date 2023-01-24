#ifndef MODEL_H
#define MODEL_H

#include "lib_agents.h"

using std::vector;
using std::string;

namespace s21 {
class Model {
 public:
  Model() {};
  std::vector<std::string> starting_cpu_agent(bool check);
  std::vector<std::string> starting_memory_agent(bool check);
  std::vector<std::string> starting_network_agent(std::string url, bool check);
  std::vector<std::string> starting_special_agent(std::string lvl_privilege, bool check);

  std::vector<std::string> starting_agents(bool cpu, bool memory, bool network, std::string url);

  std::vector<int> load_value_from_config();
};
}  // namespace s21

#endif

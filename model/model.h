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

  std::vector<std::string> starting_agents(bool cpu, bool memory, bool network, std::string url);
};
}  // namespace s21

#endif

#ifndef MODEL_H
#define MODEL_H

#include "lib_agents.h"

using std::vector;
using std::string;

namespace s21 {
class Model {
 public:
  Model() {};
  void starting_cpu_agent(bool check);
  void starting_memory_agent(bool check);
  void starting_network_agent(std::string url, bool check);

  void starting_agents(bool cpu, bool memory, bool network, std::string url);
};
}  // namespace s21

#endif

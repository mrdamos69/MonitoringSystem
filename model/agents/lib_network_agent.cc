#include "lib_agents.h"
namespace {
std::string validation_url(std::string &url) {
  std::string command =
      "curl -I " + url + " -o /dev/null -s -w '%{http_code}\n'";
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  return (std::stod(output) == 200 ? "available" : "not available");
}

double speed_network() {
  std::string command;
  if (SYSTEM_CHECK) {
    command = "netstat -bI en0 | grep -E \"en0|Bytes\" | grep -v \"Refs\" "
              "| awk '{print $7}' | tail -1";
  } else {
    command = "bash -c 'cat /proc/net/dev'";
  }
  std::string output = "";
  char buffer[128];
  std::FILE *pipe = popen(command.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (!std::feof(pipe)) {
    if (std::fgets(buffer, 128, pipe) != NULL)
      output += buffer;
  }
  pclose(pipe);
  if (SYSTEM_CHECK) {
    return std::stod(output) / 1024 / 1024 / 1024;
  }
  std::smatch match;
  std::regex pattern("[a-z]+:\\s+(\\d+)\\s+(\\d+)");
  double inet_through = 0;
  while (std::regex_search(output, match, pattern)) {
    double rx = std::stod(match[1]);
    double tx = std::stod(match[2]);
    inet_through += rx + tx;
    output = match.suffix().str();
  }
  return inet_through;
}
} // namespace

void Lib_agent::network_agent(std::string &url) {
  std::string result;
  double speed_network_ = speed_network();
  std::string url_ = validation_url(url);
  result = get_time() + " | " + url + " : " + url_ + " | " + "inet_throughput" +
           " : " + std::to_string(speed_network_);
  input_file(result);
  system_metrics.insert(
      std::make_pair("url", ((url_ == "not available") ? 1 : 0)));
  system_metrics.insert(std::make_pair("inet_throughput", speed_network_));
}

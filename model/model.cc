#include "model.h"

  std::vector<double> s21::Model::starting_cpu_agent(bool check) {
    std::vector<double> result;
    if(check) {
      std::cout << "\nTR_1_ID: " << std::this_thread::get_id() << std::endl;
      double cpu_usage = this->cpu_load();
      int processes = this->number_of_processes();
      result.push_back(cpu_usage);
      result.push_back(processes);
    }
    // for(auto&&i : result) {
    //   std::cout << i << std::endl;
    // }
    return result;
  }

   double s21::Model::cpu_load() {
    std::string command = "top -l 1 | grep -E \"^CPU\" | awk '{print $3}' | cut -c 1-4";
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
    return std::stod(output);
  }

  int s21::Model::number_of_processes() {
    std::string command = "ps -e | wc -l | cut -c 6-8";
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
    return std::stod(output);
  }

  // void s21::Model::download_file_with_marks_memory() {
  //   std::fstream myfile;
  //   myfile.open ("text.txt", std::ios_base::app);
  //   std::string ram_total = "system_profiler SPHardwareDataType | grep \"Memory\" | awk '{print $2}' \n";
  //   std::string ram = " ps -caxm -orss= | awk '{ sum += $1 } END { print sum/1024/1024 }' \n";
  //   std::string hard_volume = " df -H | awk '{ sum = /\\/dev\\/disk3/ } END {print $3}' | cut -c 1-3 \n";
  //   std::string hard_ops = "iostat -c 1 -w 10 disk0 | awk '{print $1}'| tail -1 \n";
  //   std::string hard_throughput = "iostat -c 1 -w 10 disk3 | awk '{print $1}'| tail -1";
  //   std::array<char, 80> buffer;
  //   std::vector<std::string> marks = {ram_total, ram, hard_volume, hard_ops, hard_throughput};
  //   for (auto i : marks) {
  //   FILE* pipe = popen(i.c_str(), "r+");
  //   while (fgets(buffer.data(), 80, pipe) != nullptr)
  //     myfile << buffer.data();
  //   pclose(pipe);
  //   }
  //   myfile.close();
  // }
  
  vector<double> s21::Model::starting_memory_agent(bool check) {
    std::vector<double> result;
    if(check) {
      std::cout << "\nTR_2_ID: " << std::this_thread::get_id() << std::endl;
      double ram_total = this->ram_total();
      double ram = this->ram();
      double hard_volume = this->hard_volume();
      double hard_ops = this->hard_ops();
      double hard_throughput = this->hard_throughput();
      result.push_back(ram_total);
      result.push_back(ram);
      result.push_back(hard_volume);
      result.push_back(hard_ops);
      result.push_back(hard_throughput);
    }
    // for(auto&&i : result) {
    //   std::cout << i << std::endl;
    // }
    return result;
  }

  double s21::Model::ram_total() {
    std::string command = "system_profiler SPHardwareDataType | grep \"Memory\" | awk '{print $2}'";
    std::string output = "ps -caxm -orss= | awk '{ sum += $1 } END { print sum/1024/1024 }'";
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
    return std::stod(output);
  }

  double s21::Model::ram() {
    std::string command = "bash -c 'free -m | awk '/Mem:/ {print 100 - $4*100/$2}''";
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
    return std::stod(output);
  }

  double s21::Model::hard_volume() {
    std::string command = "df -H | awk '{ sum = /\\/dev\\/disk3/ } END {print $3}' | cut -c 1-3";
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
    return std::stod(output);
  }

  double s21::Model::hard_ops() {
    std::string command = "iostat -c 1 -w 10 disk0 | awk '{print $1}'| tail -1";
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
    return std::stod(output);
  }

  double s21::Model::hard_throughput() {
    std::string command = "iostat -c 1 -w 10 disk3 | awk '{print $1}'| tail -1";
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
    return std::stod(output);
  }

  std::pair<bool, double> s21::Model::starting_network_agent(std::string url, bool check) {
    if(check) {
      std::cout << "\nTR_3_ID: " << std::this_thread::get_id() << std::endl;
      return std::pair<bool, double> (validation_url(url), speed_network());
    } else {
      return std::pair<bool, double> (0, 0);
    }
  }

  void s21::Model::uploading_data_to_file(const std::vector<double>& data1,
                                          const std::vector<double>& data2,
                                          std::pair<bool, double> config) {
    std::ofstream file("config.conf");
    file << "Data1:" << std::endl;
    for (double d : data1) {
        file << d << std::endl;
    }
    file << "Data2:" << std::endl;
    for (double d : data2) {
        file << d << std::endl;
    }
    file << "Configuration:" << std::endl;
    file << "Option: " << config.first << std::endl;
    file << "Value: " << config.second << std::endl;
    file.close();
  }

  bool s21::Model::validation_url(std::string url) {
    std::string command = "curl -I " + url + " -o /dev/null -s -w '%{http_code}\n'";
    int status = std::system(command.c_str());
    return (status == 0 ? true : false);
  }

  double s21::Model::speed_network() {
    std::string command = "netstat -bI en0 | grep -E ""en0|Bytes"" | grep -v ""Refs"" | awk '{print $7}'";
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

  void s21::Model::starting_agents(bool cpu, bool memory, bool network, std::string url) {
      std::vector<double> result;
      std::thread thread_1([this, cpu](){
        this->starting_cpu_agent(cpu);
      });

      std::thread thread_2([this, memory](){
        this->starting_memory_agent(memory);
      });

      std::thread thread_3([this, url, network](){
        this->starting_network_agent(url.data(), network);
      });
      thread_1.join();
      thread_2.join();
      thread_3.join();
  }
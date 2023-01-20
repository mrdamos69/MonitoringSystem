#include "model.h"

  // std::pair<double, int> s21::Model::starting_cpu_agent() {
  //   double cpu;
  //   int processes;
    
  //   return std::pair<double, int> ();
  // }
  void s21::Model::download_file_with_marks_memory() {
    std::fstream myfile;
    myfile.open ("text.txt", std::ios_base::app);
    std::string ram_total = "system_profiler SPHardwareDataType | grep \"Memory\" | awk '{print $2}' \n";
    std::string ram = " ps -caxm -orss= | awk '{ sum += $1 } END { print sum/1024/1024 }' \n";
    std::string hard_volume = " df -H | awk '{ sum = /\\/dev\\/disk3/ } END {print $3}' | cut -c 1-3 \n";
    std::string hard_ops = "iostat -c 1 -w 10 disk0 | awk '{print $1}'| tail -1 \n";
    std::string hard_throughput = "iostat -c 1 -w 10 disk3 | awk '{print $1}'| tail -1";
    std::array<char, 80> buffer;
    std::vector<std::string> marks = {ram_total, ram, hard_volume, hard_ops, hard_throughput};
    for (auto i : marks) {
    FILE* pipe = popen(i.c_str(), "r+");
    while (fgets(buffer.data(), 80, pipe) != nullptr)
        myfile << buffer.data();
    pclose(pipe);
    }
    myfile.close();
  }
  
  vector<double> s21::Model::starting_memory_agent() {
   download_file_with_marks_memory(); 
   std::ifstream file("text.txt");
   std::vector<double> v; //Вектор строк
   std::string S;  //Считываемое слово из файла
   while(std::getline(file, S)) { 
   v.push_back(atof(S.data()));  //Считывание в вектор с указанием разделителя
   }
//    for (unsigned int i=0;i<v.size();i++) std::cout<<v.at(i)<<" "; //Вывод вектора на экран
  return v;
  }

  std::pair<bool, double> s21::Model::starting_network_agent(std::string url) {
    return std::pair<bool, double> (validation_url(url), speed_network());
  }

  // void s21::Model::uploading_data_to_file(double cpu, int processes,
  //                                         double ram_total, double ram,
  //                                         double hard_volume, int hard_ops,
  //                                         double hard_throughput, bool network_url,
  //                                         double doubleinet_throughput) {
    
  // }

  bool s21::Model::validation_url(std::string url) {
    std::string curl = "curl ";
    std::string script = curl + url + " >> temp_file_8.conf";
    std::system(script.data());
    int count = 0;
    std::ifstream temp_file("temp_file_8.conf");
    if (!temp_file.eof()) {
      std::string lineptr;
      while (std::getline(temp_file, lineptr))
        count++;
    }
    temp_file.close();
    std::system("rm temp_file_8.conf");
    return (count > 1 ? true : false);
  }

  double s21::Model::speed_network() {
    std::string script = "speedtest | awk '/Download:/ { print $2 }' >> temp_file_9.conf";
    std::system(script.data());
    std::string lineptr;
    std::ifstream temp_file("temp_file_9.conf");
    if (!temp_file.eof()) {
      std::getline(temp_file, lineptr);
    }
    temp_file.close();
    std::system("rm temp_file_9.conf");
    return atof(lineptr.data());
  }
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main() {
  // std::string url = "https://edu.21-school.ru";
  // std::string curl = "curl ";
  // std::string script = curl + url + " >> temp_file.conf";
  // std::system(script.data());
  // int count = 0;

  // std::ifstream temp_file("temp_file.conf");
  // if (!temp_file.eof()) {
  //     std::string lineptr;
  //     while (std::getline(temp_file, lineptr)) {
  //         count++;
  //     }
  // }
  // temp_file.close();
  // std::system("rm temp_file.conf");
  // std::cout << (count > 1 ? true : false) << std::endl;
  // return 0;

  
  std::string script = "speedtest | awk '/Download:/ { print $2 }' >> temp_file.conf";
  std::system(script.data());
  std::string lineptr;

  std::ifstream temp_file("temp_file.conf");
  if (!temp_file.eof()) {
    std::getline(temp_file, lineptr);
  }
  temp_file.close();
  std::system("rm temp_file.conf");

  std::cout << atof(lineptr.data()) << std::endl;
  return 0;
}
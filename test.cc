#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <vector>
int main() {
    std::fstream myfile;
    myfile.open ("text.txt", std::ios_base::app);
    std::string ram_total = "system_profiler SPHardwareDataType | grep \"Memory\" | awk '{print $2}' \n";
    std::string ram = " ps -caxm -orss= | awk '{ sum += $1 } END { print sum/1024/1024 }' \n";
    std::string hard_volume = " df -H | awk '{ sum = /\\/dev\\/disk3/ } END {print $3}' \n";
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
 return 0;
}
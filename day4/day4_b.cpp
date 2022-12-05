#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>
#include <regex>

const std::string FILENAME = "day4_input.txt";

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f;
    f.open(FILENAME);
    std::string line;
    std::vector<int> ranges(4, 0);
    int count = 0;
    std::regex rgx("^(\\d+)-(\\d+),(\\d+)-(\\d+)$");
    std::smatch sm;
    while(std::getline(f, line)) {
        if(!std::regex_match(line, sm, rgx)) std::cerr << "Invalid input file.\n";
        for(size_t i = 1; i < sm.size(); ++i) ranges[i - 1] = stoi(sm[i]);
        count += !(ranges[0] > ranges[3] || ranges[2] > ranges[1]);
    }
    f.close();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(
                   std::chrono::high_resolution_clock::now() - start);
    std::cout << "There are " << count << " overlapping pairs.\n" <<
                 "Computed in " << runtime.count() << " ms.";
}
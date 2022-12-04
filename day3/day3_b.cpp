#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

const std::string FILENAME = "day3_input.txt";
const int NUM_CHARS = 52;
const size_t GROUP_SIZE = 3;

int get_score(char c);

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f;
    f.open(FILENAME);
    std::string line;
    int total_score = 0;
    while(!f.eof()) {
        std::vector<bool> group_common(NUM_CHARS, 1);
        for(size_t i = 0; i < GROUP_SIZE; ++i) {
            std::getline(f, line);
            std::vector<bool> group_found(NUM_CHARS, 0);
            for(char c: line) group_found[get_score(c) - 1] = 1;
            for(size_t j = 0; j < group_common.size(); ++j) {
                group_common[j] = group_common[j] & group_found[j];
            }
        }
        for(size_t i = 0; i < group_common.size(); ++i) {
            if(group_common[i]) {
                total_score += i + 1;
                break;
            }
        }
    }
    f.close();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(
                   std::chrono::high_resolution_clock::now() - start);
    std::cout << "The total score is " << total_score <<
                 ".\nComputed in " << runtime.count() << " ms.";
}

int get_score(char c) {
    if(c <= 'Z') return c - 'A' + 27;
    return c - 'a' + 1;
}
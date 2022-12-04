#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

const std::string FILENAME = "day3_input.txt";
const int NUM_CHARS = 52;

int get_score(char c);

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f;
    f.open(FILENAME);
    std::string line;
    int total_score = 0;
    while(std::getline(f, line)) {
        std::vector<bool> first_compartment(NUM_CHARS, 0); 
        for(size_t i = 0; i < line.size() / 2; ++i) {
            int score = get_score(line[i]);
            first_compartment[score - 1] = 1;
        }
        for(size_t i = line.size() / 2; i < line.size(); ++i) {
            int score = get_score(line[i]);
            if(first_compartment[score - 1]) {
                total_score += score;
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
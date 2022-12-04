#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#define WIN 0
#define LOSE 1
#define DRAW 2
const std::string FILENAME = "day2_input.txt";
const std::vector<int> outcome_mapping = {LOSE, DRAW, WIN}; 
const int n = 3;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f;
    f.open(FILENAME);
    std::string line;
    int this_move, opp_move, outcome;
    int score = 0;
    while(std::getline(f, line)) {
        outcome = (line[2] - 'X');
        opp_move = (line[0] - 'A' + 1);
        score += outcome * 3;
        this_move = (outcome_mapping[outcome] + opp_move) % n + 1;
        score += this_move;
    }
    f.close();
    auto prog_time = std::chrono::duration_cast<std::chrono::microseconds>(
                     std::chrono::high_resolution_clock::now() - start);
    std::cout << "The final score would be " << score << ".\n" <<
                 "Computed in " << (prog_time.count()) << " ms.";
}

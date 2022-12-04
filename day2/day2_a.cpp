#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#define WIN_SCORE 6
#define DRAW_SCORE 3
#define LOSS_SCORE 0

const std::string FILENAME = "day2_input.txt";
const std::vector<int> result_score = {WIN_SCORE, LOSS_SCORE, DRAW_SCORE};
const int n = 3;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f;
    f.open(FILENAME);
    std::string line;
    int this_move, opp_move;
    int score = 0;
    while(std::getline(f, line)) {
        this_move = (line[2] - 'X' + 1);
        opp_move = (line[0] - 'A' + 1);
        score += this_move;
        score += result_score[(this_move + (n - 1) - opp_move) % n];
        //score += (((this_move + (n - 1) - opp_move) % n + 2) % 3) * 3;
    }
    f.close();
    auto prog_time = std::chrono::duration_cast<std::chrono::microseconds>(
                     std::chrono::high_resolution_clock::now() - start);
    std::cout << "The final score would be " << score << ".\n" <<
                 "Computed in " << (prog_time.count()) << " ms.";
}

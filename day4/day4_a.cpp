#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

const std::string FILENAME = "day4_input.txt";

std::vector<int> tokenize(const std::string& line);

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream f;
    f.open(FILENAME);
    std::string line;
    std::vector<int> ranges;
    int count = 0;
    while(std::getline(f, line)) {
        ranges = tokenize(line);
        count += (ranges[0] <= ranges[2] && ranges[1] >= ranges[3]) ||
                 (ranges[2] <= ranges[0] && ranges[3] >= ranges[1]);
    }
    f.close();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(
                   std::chrono::high_resolution_clock::now() - start);
    std::cout << "There are " << count << " overlapping pairs.\n" <<
                 "Computed in " << runtime.count() << " ms.";
}


std::vector<int> tokenize(const std::string& line) {
    const std::string delim = ",-";

    std::string token;
    std::vector<int> tokenized;
    std::vector<bool> isDelim(UCHAR_MAX, false);
    for(char d: delim) isDelim[d] = true;

    for(char t: line) {
        if(isDelim[t]) {
            if(!token.empty()) { tokenized.push_back(std::stoi(token)); token.clear(); }
        }
        else token.push_back(t);
    }
    if(!token.empty()) tokenized.push_back(std::stoi(token));

    return tokenized;
}

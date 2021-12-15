#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    unordered_map<char, char> openingPair = {
        {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};

    unordered_map<char, int> illegalCharPoints = {
        {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};

    int score = 0;

    string line;
    while (inputFile >> line) {
        stack<char> chunk;
        bool corrupted = false;

        for (char c : line) {
            switch (c) {
                case ')':
                case ']':
                case '}':
                case '>':
                    if (chunk.top() == openingPair.at(c)) {
                        chunk.pop();
                    } else {
                        corrupted = true;
                    }
                    break;
                default:
                    chunk.push(c);
                    break;
            }

            if (corrupted) {
                score += illegalCharPoints.at(c);
                break;
            }
        }
    }

    cout << score << endl;
}

int main() {
    // inputFile.open("sample_input.txt");
    inputFile.open("input.txt");

    if (!inputFile.good()) {
        cout << "Input file error" << endl;
        return -1;
    }

    puzzle();
    inputFile.close();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    unordered_map<char, char> openingPair = {
        {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};

    unordered_map<char, char> closingPair = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};

    unordered_map<char, int> points = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};

    vector<unsigned long long> scores;

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
                break;
            }
        }

        if (!corrupted) {
            // Incomplete
            unsigned long long score = 0L;

            while (!chunk.empty()) {
                char c = chunk.top();
                char closingChar = closingPair.at(c);
                score *= 5;
                score += points.at(closingChar);
                chunk.pop();
            }

            scores.push_back(score);
        }
    }

    sort(scores.begin(), scores.end());
    cout << scores[scores.size() / 2] << endl;
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
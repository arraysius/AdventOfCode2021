#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    string command;
    int value;
    while (inputFile >> command >> value) {
        if (command == "forward") {
            horizontal += value;
            depth += aim * value;
        } else if (command == "up") {
            aim -= value;
        } else if (command == "down") {
            aim += value;
        }
    }

    cout << horizontal * depth << endl;
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
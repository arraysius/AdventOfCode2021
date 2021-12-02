#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    int horizontal = 0;
    int depth = 0;

    string command;
    int value;
    while (inputFile >> command >> value) {
        if (command == "forward") {
            horizontal += value;
        } else if (command == "up") {
            depth -= value;
        } else if (command == "down") {
            depth += value;
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
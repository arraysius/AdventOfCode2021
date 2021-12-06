#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    string line;
    getline(inputFile, line);
    istringstream iss(line);

    vector<int> fishTimers;

    string timer;
    while (getline(iss, timer, ',')) {
        fishTimers.push_back(stoi(timer));
    }

    for (int i = 0; i < 80; i++) {
        int currSize = fishTimers.size();
        for (int j = 0; j < currSize; j++) {
            if (fishTimers[j] == 0) {
                fishTimers[j] = 6;
                fishTimers.push_back(8);
            } else {
                fishTimers[j]--;
            }
        }
    }

    cout << fishTimers.size() << endl;
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
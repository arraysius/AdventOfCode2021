#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    string line;
    getline(inputFile, line);
    istringstream iss(line);

    unsigned long long fishTimerCount[9] = {0L};

    string timer;
    while (getline(iss, timer, ',')) {
        fishTimerCount[stoi(timer)]++;
    }

    for (int i = 0; i < 256; i++) {
        unsigned long long newFishes = fishTimerCount[0];

        // Shift timer down one position
        for (int j = 0; j < 8; j++) {
            fishTimerCount[j] = fishTimerCount[j + 1];
        }

        // Add resetted fishes
        fishTimerCount[6] += newFishes;

        // Set spawned fishes
        fishTimerCount[8] = newFishes;
    }

    cout << accumulate(fishTimerCount, fishTimerCount + 9, 0L) << endl;
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
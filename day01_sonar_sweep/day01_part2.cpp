#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    int incrementCount = 0;
    deque<int> window;
    int depth;

    // Read first 2 windows
    for (int i = 0; i < 4; i++) {
        inputFile >> depth;
        window.push_back(depth);
    }

    do {
        int window1Sum = accumulate(window.begin(), next(window.begin(), 3), 0);
        int window2Sum = accumulate(next(window.begin(), 1), window.end(), 0);

        if (window2Sum > window1Sum) {
            incrementCount++;
        }

        // Update to next window
        window.pop_front();

        inputFile >> depth;
        window.push_back(depth);
    } while (inputFile.peek() != EOF);

    cout << incrementCount << endl;
}

int main() {
    // inputFile.open("sample_input.txt");
    inputFile.open("input.txt");

    if (!inputFile.good()) {
        cout << "Input file error" << endl;
        return 0;
    }

    puzzle();
    inputFile.close();

    return 0;
}
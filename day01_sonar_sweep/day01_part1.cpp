#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    int incrementCount = 0;
    int last = -1, next;

    while (inputFile >> next) {
        // Check increment from second read onwards
        if (last != -1 && next > last) {
            incrementCount++;
        }

        last = next;
    }

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
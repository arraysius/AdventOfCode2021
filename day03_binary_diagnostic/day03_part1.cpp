#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    int gamma = 0;
    int epsilon = 0;

    int totalNumbers = 0;
    vector<int> oneBitCount;
    vector<string> binaryNumbers;

    string binaryNumber;
    int binaryLength;

    while (inputFile >> binaryNumber) {
        totalNumbers++;
        binaryNumbers.push_back(binaryNumber);

        // Initialise vector
        if (totalNumbers == 1) {
            binaryLength = binaryNumber.length();
            for (int i = 0; i < binaryLength; i++) {
                oneBitCount.push_back(0);
            }
        }

        // Count 1 bits
        for (int i = 0; i < binaryLength; i++) {
            char binaryDigit = binaryNumber.at(i);
            if (binaryDigit == '1') {
                oneBitCount[i]++;
            }
        }
    }

    // Calculate gamma rating
    for (int i = 0; i < binaryLength; i++) {
        if (oneBitCount[i] > (totalNumbers / 2)) {
            gamma += pow(2, binaryLength - i - 1);
        }
    }

    // Calculate epsilong rating by one's complement
    epsilon = pow(2, binaryLength) - gamma - 1;

    cout << "gamma rating: " << gamma << endl;
    cout << "epsilon rating: " << epsilon << endl;
    cout << "total: " << gamma * epsilon << endl;
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
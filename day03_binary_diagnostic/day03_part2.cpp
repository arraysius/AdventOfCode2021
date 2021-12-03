#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

int calcCommonBit(vector<string> numbers, int position) {
    int common;
    int bits[2] = {0, 0};

    for (string number : numbers) {
        if (number.at(position) == '0') {
            bits[0]++;
        } else {
            bits[1]++;
        }
    }

    if (bits[0] > bits[1]) {
        return 0;
    } else if (bits[0] < bits[1]) {
        return 1;
    } else {
        return 2;
    }
}

void puzzle() {
    int gamma = 0;
    int epsilon = 0;
    int oxygenGenerator = 0;
    int co2scrubber = 0;

    vector<int> oneBitCount;
    vector<string> binaryNumbers;

    string binaryNumber;
    int binaryLength;

    while (inputFile >> binaryNumber) {
        binaryNumbers.push_back(binaryNumber);
    }

    binaryLength = binaryNumber.length();

    // Calculate oxygen generator rating
    vector<string> subNumbers = binaryNumbers;
    for (int i = 0; i < binaryLength; i++) {
        int commonBit = calcCommonBit(subNumbers, i);
        if (commonBit == 2) {
            commonBit = 1;
        }

        subNumbers.erase(remove_if(subNumbers.begin(), subNumbers.end(), [i, commonBit](string s) {
            return s.at(i) - '0' == commonBit;
        }), subNumbers.end());

        if (subNumbers.size() == 1) {
            oxygenGenerator = stoi(subNumbers[0], 0, 2);
            break;
        }
    }

    // Calculate co2scrubber rating
    subNumbers = binaryNumbers;
    for (int i = 0; i < binaryLength; i++) {
        int commonBit = calcCommonBit(subNumbers, i);

        // Invert common bit to least common
        if (commonBit == 1 || commonBit == 2) {
            commonBit = 0;
        } else {
            commonBit = 1;
        }

        subNumbers.erase(remove_if(subNumbers.begin(), subNumbers.end(), [i, commonBit](string s) {
            return s.at(i) - '0' == commonBit;
        }), subNumbers.end());

        if (subNumbers.size() == 1) {
            co2scrubber = stoi(subNumbers[0], 0, 2);
            break;
        }
    }

    cout << "oxygen rating: " << oxygenGenerator << endl;
    cout << "co2 scrubber rating: " << co2scrubber << endl;
    cout << "total: " << oxygenGenerator * co2scrubber << endl;
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
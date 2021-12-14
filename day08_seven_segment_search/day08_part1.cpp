#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    vector<string> outputs;

    // 1, 4, 7, 8
    vector<int> uniqueDigitsCount(4, 0);

    string temp;

    while (getline(inputFile, temp, '|')) {
        // Read outputs
        for (int i = 0; i < 4; i++) {
            inputFile >> temp;
            outputs.push_back(temp);

            switch (temp.size()) {
                case 2:
                    // 1
                    uniqueDigitsCount[0]++;
                    break;
                case 4:
                    // 4
                    uniqueDigitsCount[1]++;
                    break;
                case 3:
                    // 7
                    uniqueDigitsCount[2]++;
                    break;
                case 7:
                    // 8
                    uniqueDigitsCount[3]++;
                    break;
                default:
                    break;
            }
        }
    }

    cout << accumulate(uniqueDigitsCount.begin(), uniqueDigitsCount.end(), 0) << endl;
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
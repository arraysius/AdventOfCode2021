#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    /*
    Solution adapted from u/PittGreek1969
    https://www.reddit.com/r/adventofcode/comments/rbvpui/2021_day_8_part_2_my_logic_on_paper_i_used_python/
    */

    unsigned int sum = 0;
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);

        vector<vector<char>> inputChars;
        vector<vector<char>> digits(10, vector<char>());
        vector<char> fourDiff;

        // Read inputs
        for (int i = 0; i < 10; i++) {
            string inputString;
            iss >> inputString;
            sort(inputString.begin(), inputString.end());
            vector<char> inputChar(inputString.begin(), inputString.end());

            switch (inputString.size()) {
                case 2:
                    // 1
                    digits[1] = inputChar;
                    break;
                case 4:
                    // 4
                    digits[4] = inputChar;
                    break;
                case 3:
                    // 7
                    digits[7] = inputChar;
                    break;
                case 7:
                    // 8
                    digits[8] = inputChar;
                    break;
                default:
                    inputChars.push_back(inputChar);
                    break;
            }
        }

        // Calculate fourdiff "L" shape
        set_difference(digits[4].begin(), digits[4].end(), digits[1].begin(),
                       digits[1].end(), back_inserter(fourDiff));

        for (vector<char> inputChar : inputChars) {
            if (inputChar.size() == 5) {
                if (includes(inputChar.begin(), inputChar.end(),
                             digits[1].begin(), digits[1].end())) {
                    // 3
                    digits[3] = inputChar;
                } else if (includes(inputChar.begin(), inputChar.end(),
                                    fourDiff.begin(), fourDiff.end())) {
                    // 5
                    digits[5] = inputChar;
                } else {
                    // 2
                    digits[2] = inputChar;
                }
            } else {
                // Size == 6
                if (includes(inputChar.begin(), inputChar.end(),
                             digits[4].begin(), digits[4].end())) {
                    // 9
                    digits[9] = inputChar;
                } else if (includes(inputChar.begin(), inputChar.end(),
                                    fourDiff.begin(), fourDiff.end())) {
                    // 6
                    digits[6] = inputChar;
                } else {
                    // 0
                    digits[0] = inputChar;
                }
            }
        }

        // Read divider "|"
        char temp;
        iss >> temp;

        // Read ouputs
        int outputValue = 0;
        for (int i = 0; i < 4; i++) {
            string outputString;
            iss >> outputString;
            sort(outputString.begin(), outputString.end());
            vector<char> outputChar(outputString.begin(), outputString.end());

            vector<vector<char>>::iterator it =
                find(digits.begin(), digits.end(), outputChar);
            int digit = distance(digits.begin(), it);
            outputValue *= 10;
            outputValue += digit;
        }

        sum += outputValue;
    }

    cout << sum << endl;
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
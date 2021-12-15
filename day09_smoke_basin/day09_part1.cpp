#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    unsigned int riskLevel = 0;

    // Directions (row, column): up, down, left, right
    vector<pair<int, int>> directions = {
        make_pair(-1, 0),
        make_pair(1, 0),
        make_pair(0, -1),
        make_pair(0, 1)
    };

    vector<vector<int>> grid;

    string line;
    while (getline(inputFile, line)) {
        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        grid.push_back(row);
    }

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            bool lower = true;
            int currValue = grid[row][col];

            for (pair<int, int> direction : directions) {
                int adjRow = row + direction.first;
                int adjCol = col + direction.second;

                bool inRow = adjRow >= 0 && adjRow < grid.size();
                bool inCol = adjCol >= 0 && adjCol < grid[row].size();
                if (!(inRow && inCol)) {
                    continue;
                }

                int adjValue = grid[adjRow][adjCol];
                if (currValue >= adjValue) {
                    lower = false;
                    break;
                }
            }

            if (lower) {
                riskLevel += currValue + 1;
            }
        }
    }

    cout << riskLevel << endl;
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
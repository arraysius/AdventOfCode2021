#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

vector<vector<bool>> visited;
vector<vector<int>> grid;
int basinSize;
priority_queue<int, vector<int>, greater<int>> pq;

// Directions (row, column): up, down, left, right
vector<pair<int, int>> directions = {make_pair(-1, 0), make_pair(1, 0),
                                     make_pair(0, -1), make_pair(0, 1)};

void searchBasin(pair<int, int> pos) {
    visited[pos.first][pos.second] = true;
    basinSize++;

    for (pair<int, int> direction : directions) {
        int adjRow = pos.first + direction.first;
        int adjCol = pos.second + direction.second;

        bool inRow = adjRow >= 0 && adjRow < grid.size();
        bool inCol = adjCol >= 0 && adjCol < grid[pos.first].size();
        if (!(inRow && inCol) || visited[adjRow][adjCol]) {
            continue;
        }

        int currValue = grid[pos.first][pos.second];
        int adjValue = grid[adjRow][adjCol];

        if (adjValue > currValue && adjValue != 9) {
            searchBasin(make_pair(adjRow, adjCol));
        }
    }
};

void puzzle() {
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
                visited = vector<vector<bool>>(
                    grid.size(), vector<bool>(grid[0].size(), false));
                basinSize = 0;
                searchBasin(make_pair(row, col));

                pq.push(basinSize);
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
        }
    }

    unsigned int total = 1;
    while (!pq.empty()) {
        total *= pq.top();
        pq.pop();
    }

    cout << total << endl;
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
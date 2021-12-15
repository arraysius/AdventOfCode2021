#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

// Directions (row, column):
// Upper left, up, upper right
// Left, right
// Bottom left, down, botton right
vector<pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
};

vector<vector<int>> grid(10, vector<int>(10, -1));
vector<vector<bool>> visited;

void flash(int row, int col) {
    visited[row][col] = true;

    for (pair<int, int> direction : directions) {
        int adjRow = row + direction.first;
        int adjCol = col + direction.second;

        bool inRow = adjRow >= 0 && adjRow < 10;
        bool inCol = adjCol >= 0 && adjCol < 10;
        if (!(inRow && inCol) || grid[adjRow][adjCol] == 0) {
            continue;
        }

        grid[adjRow][adjCol] = (grid[adjRow][adjCol] + 1) % 10;

        if (grid[adjRow][adjCol] == 0) {
            flash(adjRow, adjCol);
        }
    }
}

void puzzle() {
    // Read input
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char energy;
            inputFile >> energy;
            grid[i][j] = energy - '0';
        }
    }

    int steps;
    for (steps = 0;; steps++) {
        // Increment
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = (grid[i][j] + 1) % 10;
            }
        }

        // Flashes
        visited = vector<vector<bool>>(10, vector<bool>(10, false));
        for (int row = 0; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                if (grid[row][col] == 0 && !visited[row][col]) {
                    flash(row, col);
                }
            }
        }

        int synced = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                synced += grid[i][j];

                if (synced > 0) {
                    break;
                }
            }

            if (synced > 0) {
                break;
            }
        }

        if (synced == 0) {
            break;
        }
    }

    cout << steps + 1 << endl;
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
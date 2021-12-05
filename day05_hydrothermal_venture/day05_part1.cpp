#include <bits/stdc++.h>

// #define VENT_SIZE 10
#define VENT_SIZE 1000

using namespace std;

ifstream inputFile;

void puzzle() {
    int vents[VENT_SIZE][VENT_SIZE] = {0};
    int points = 0;

    char c;
    int x1, y1, x2, y2;

    while (inputFile >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2) {
        if (!(x1 == x2 || y1 == y2)) {
            continue;
        }

        int minX = min(x1, x2);
        int maxX = max(x1, x2);
        int minY = min(y1, y2);
        int maxY = max(y1, y2);

        if (x1 == x2) {
            // Vertical line
            for (int y = minY; y <= maxY; y++) {
                vents[x1][y]++;
            }
        } else if (y1 == y2) {
            // Horizontal line
            for (int x = minX; x <= maxX; x++) {
                vents[x][y1]++;
            }
        }
    }

    // Print map
    for (int y = 0; y < VENT_SIZE; y++) {
        for (int x = 0; x < VENT_SIZE; x++) {
            if (vents[x][y] > 0) {
                cout << vents[x][y];
            } else {
                cout << ".";
            }

            if (vents[x][y] >= 2) {
                points++;
            }
        }
        cout << endl;
    }

    cout << endl << "points: " << points << endl;
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
#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    vector<pair<int, int>> dotPositions;
    vector<vector<char>> paper;
    int maxX = 0, maxY = 0;

    string line;
    char _;

    // Read positions
    while (getline(inputFile, line)) {
        if (line.empty()) {
            break;
        }

        istringstream iss(line);
        int x, y;
        iss >> x >> _ >> y;

        maxX = max(maxX, x);
        maxY = max(maxY, y);
        dotPositions.push_back(make_pair(x, y));
    }

    maxX += 1;
    maxY += 1;

    paper = vector<vector<char>>(maxY, vector<char>(maxX, '.'));
    for (pair<int, int> dot : dotPositions) {
        paper[dot.second][dot.first] = '#';
    }

    // Read fold
    char foldDirection;
    int foldPosition;
    while (inputFile >> line >> line >> foldDirection >> _ >> foldPosition) {
        vector<vector<char>> foldedPaper;
        if (foldDirection == 'y') {
            // Prepare folded paper
            foldedPaper = vector<vector<char>>(
                foldPosition, vector<char>(paper[0].size(), '.'));
            for (int row = 0; row < foldPosition; row++) {
                for (int col = 0; col < paper[row].size(); col++) {
                    if (paper[row][col] == '#') {
                        foldedPaper[row][col] = '#';
                    }
                }
            }

            // Fold paper
            for (int row = foldPosition + 1; row < paper.size(); row++) {
                int diff = row - foldPosition;
                for (int col = 0; col < paper[row].size(); col++) {
                    if (paper[row][col] == '#') {
                        foldedPaper[row - (diff * 2)][col] = '#';
                    }
                }
            }
        } else if (foldDirection == 'x') {
            // Prepare folded paper
            foldedPaper = vector<vector<char>>(paper.size(),
                                               vector<char>(foldPosition, '.'));
            for (int row = 0; row < paper.size(); row++) {
                for (int col = 0; col < foldPosition; col++) {
                    if (paper[row][col] == '#') {
                        foldedPaper[row][col] = '#';
                    }
                }
            }

            // Fold paper
            for (int row = 0; row < paper.size(); row++) {
                for (int col = foldPosition + 1; col < paper[row].size();
                     col++) {
                    int diff = col - foldPosition;
                    if (paper[row][col] == '#') {
                        foldedPaper[row][col - (diff * 2)] = '#';
                    }
                }
            }
        }

        paper = foldedPaper;
    }

    // Print
    for (int i = 0; i < paper.size(); i++) {
        for (int j = 0; j < paper[i].size(); j++) {
            cout << paper[i][j];
        }
        cout << endl;
    }
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
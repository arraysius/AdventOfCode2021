#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

vector<vector<int>> cave;
vector<vector<unsigned long long>> risk;

// Directions (x, y): up, down, left, right
vector<pair<int, int>> directions = {make_pair(0, -1), make_pair(0, 1),
                                     make_pair(-1, 0), make_pair(1, 0)};

// Min heap containing <risk, <x, y>>
priority_queue<pair<unsigned int, pair<int, int>>,
               vector<pair<unsigned int, pair<int, int>>>,
               greater<pair<unsigned int, pair<int, int>>>>
    pq;

void dijkstra() {
    // x : pos.first
    // y : pos.second

    while (!pq.empty()) {
        pair<unsigned int, pair<int, int>> lowestRisk = pq.top();
        pq.pop();

        pair<int, int> s = lowestRisk.second;

        if (s.first == cave.size() - 1 && s.first == s.second) {
            return;
        }

        for (pair<int, int> dir : directions) {
            int adjX = s.first + dir.first;
            int adjY = s.second + dir.second;

            bool isWithinX = adjX >= 0 && adjX < cave[0].size();
            bool isWithinY = adjY >= 0 && adjY < cave.size();
            bool isWithinCave = isWithinX && isWithinY;

            if (!isWithinCave) {
                continue;
            }

            unsigned int currTotalRisk = risk[s.second][s.first];
            int adjRisk = cave[adjY][adjX];
            unsigned int adjTotalRisk = currTotalRisk + adjRisk;

            if (adjTotalRisk < risk[adjY][adjX]) {
                risk[adjY][adjX] = adjTotalRisk;
                pq.push(make_pair(adjTotalRisk, make_pair(adjX, adjY)));
            }
        }
    }
}

void puzzle() {
    string line;
    while (getline(inputFile, line)) {
        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        cave.push_back(row);
    }

    risk = vector<vector<unsigned long long>>(
        cave.size(),
        vector<unsigned long long>(cave[0].size(), ULONG_LONG_MAX));
    risk[0][0] = 0;

    pq.push(make_pair(0, make_pair(0, 0)));
    dijkstra();

    cout << risk[risk.size() - 1][risk[0].size() - 1] << endl;
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
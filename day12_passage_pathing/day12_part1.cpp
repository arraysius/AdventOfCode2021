#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

unordered_map<string, vector<string>> adjList;

bool isLower(char c) { return islower(c); }

bool isUpper(char c) { return isupper(c); }

unsigned int dfs(string currPos, unordered_map<string, int> visits) {
    if (currPos == "end") {
        return 1;
    }

    unsigned int paths = 0;
    visits[currPos]++;

    for (string nextPos : adjList[currPos]) {
        if (nextPos == "start") {
            continue;
        }

        bool isUnvisitedSmallCave =
            all_of(nextPos.begin(), nextPos.end(), isLower) &&
            visits[nextPos] < 1;
        bool isBigCave = all_of(nextPos.begin(), nextPos.end(), isUpper);

        if (isUnvisitedSmallCave || isBigCave) {
            paths += dfs(nextPos, visits);
        }
    }

    return paths;
}

void puzzle() {
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string start, end;
        getline(iss, start, '-');
        iss >> end;

        // Add to adjacency list
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }

    // Set all cave visits to 0
    unordered_map<string, int> visits;
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        visits[it->first] = 0;
    }

    cout << dfs("start", visits) << endl;
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
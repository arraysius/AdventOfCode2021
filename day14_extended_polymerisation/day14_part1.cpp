#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    string startPolymer;
    inputFile >> startPolymer;

    unordered_map<char, int> elementFrequency;
    for (char c : startPolymer) {
        elementFrequency[c]++;
    }

    unordered_map<string, char> pairInsertion;
    string _, pairRule;
    char insertionPoly;
    while (inputFile >> pairRule >> _ >> insertionPoly) {
        pairInsertion[pairRule] = insertionPoly;
    }

    list<char> prevPolymer(startPolymer.begin(), startPolymer.end());
    list<char> nextPolymer;

    for (int step = 0; step < 10; step++) {
        nextPolymer.push_back(prevPolymer.front());
        prevPolymer.pop_front();

        while (!prevPolymer.empty()) {
            char prevCh = nextPolymer.back();
            char nextCh = prevPolymer.front();
            prevPolymer.pop_front();

            string pairRule = string() + prevCh + nextCh;
            nextPolymer.push_back(pairInsertion[pairRule]);
            elementFrequency[pairInsertion[pairRule]]++;
            nextPolymer.push_back(nextCh);
        }

        prevPolymer = nextPolymer;
        nextPolymer = list<char>();
    }

    int leastCommon = INT_MAX;
    int mostCommon = 0;
    for (pair<char, int> element : elementFrequency) {
        leastCommon = min(leastCommon, element.second);
        mostCommon = max(mostCommon, element.second);
    }

    cout << mostCommon - leastCommon << endl;
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
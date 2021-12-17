#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    string startPolymer;
    inputFile >> startPolymer;

    // Read pair insertion rules
    unordered_map<string, char> pairInsertion;
    string _, pairRule;
    char insertionPoly;
    while (inputFile >> pairRule >> _ >> insertionPoly) {
        pairInsertion[pairRule] = insertionPoly;
    }

    // Initialise pair frequency
    unordered_map<string, unsigned long long> pairFrequency;
    for (int i = 0; i < startPolymer.size() - 1; i++) {
        string p = startPolymer.substr(i, 2);
        pairFrequency[p]++;
    }

    // Initialise element frequency
    unordered_map<char, unsigned long long> elementFrequency;
    for (char c : startPolymer) {
        elementFrequency[c]++;
    }

    for (int step = 0; step < 40; step++) {
        unordered_map<string, unsigned long long> pairFrequencyCopy =
            pairFrequency;

        for (pair<string, unsigned long long> p : pairFrequencyCopy) {
            char insertionElement = pairInsertion[p.first];
            elementFrequency[insertionElement] += p.second;

            string newLeft = string() + p.first.at(0) + insertionElement;
            string newRight = string() + insertionElement + p.first.at(1);

            pairFrequency[newLeft] += p.second;
            pairFrequency[newRight] += p.second;
            pairFrequency[p.first] -= p.second;
            if (pairFrequency[p.first] == 0) {
                pairFrequency.erase(p.first);
            }
        }
    }

    unsigned long long leastCommon =
        min_element(elementFrequency.begin(), elementFrequency.end(),
                    [](pair<char, unsigned long long> a,
                       pair<char, unsigned long long> b) {
                        return a.second < b.second;
                    })
            ->second;
    unsigned long long mostCommon =
        min_element(elementFrequency.begin(), elementFrequency.end(),
                    [](pair<char, unsigned long long> a,
                       pair<char, unsigned long long> b) {
                        return a.second > b.second;
                    })
            ->second;

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
#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    vector<int> fuels;
    vector<int> spentFuel;

    string fuelString;
    while (getline(inputFile, fuelString, ',')) {
        fuels.push_back(stoi(fuelString));
    }

    // Calculate spent fuel
    for (int i = 0; i < fuels.size(); i++) {
        spentFuel.push_back(0);

        for (int j = 0; j < fuels.size(); j++) {
            int distanceFuel = abs(fuels[j] - i);
            spentFuel[i] += distanceFuel;
        }
    }

    vector<int>::iterator minFuel =
        min_element(spentFuel.begin(), spentFuel.end());
    cout << "Minimim fuel: " << *minFuel << endl;
    cout << "At index: " << distance(spentFuel.begin(), minFuel) << endl;
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
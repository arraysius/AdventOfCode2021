#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

void puzzle() {
    
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
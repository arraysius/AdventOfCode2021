#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;

class Board {
   public:
    int grid[5][5];
};

void puzzle() {
    // Read first line
    string line;
    getline(inputFile, line);

    // Split draw numbers into vector
    vector<int> drawNumbers;
    stringstream ss(line);
    while (ss.good()) {
        string number;
        getline(ss, number, ',');
        drawNumbers.push_back(stoi(number));
    }

    int winningBoard;
    int winningDraw;
    vector<Board> boards;
    vector<Board> marked;

    // Read boards
    while (true) {
        Board board;
        Board mark;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (inputFile.peek() == EOF) {
                    break;
                }

                int n;
                inputFile >> n;

                board.grid[i][j] = n;
                mark.grid[i][j] = 0;
            }

            if (inputFile.peek() == EOF) {
                break;
            }
        }

        if (inputFile.peek() == EOF) {
            break;
        }

        boards.push_back(board);
        marked.push_back(mark);
    }

    // Iterate draw number
    int won = 0;
    for (int draw : drawNumbers) {
        for (int i = 0; i < boards.size(); i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (boards[i].grid[j][k] == draw) {
                        marked[i].grid[j][k] = 1;

                        // Check across if won
                        won = 1;
                        for (int l = 0; l < 5; l++) {
                            won = won && marked[i].grid[j][l];
                        }
                        if (won) {
                            winningBoard = i;
                            winningDraw = draw;
                            break;
                        }

                        // Check down if won
                        won = 1;
                        for (int l = 0; l < 5; l++) {
                            won = won && marked[i].grid[l][k];
                        }
                        if (won) {
                            winningBoard = i;
                            winningDraw = draw;
                            break;
                        }
                    }

                    if (won) {
                        break;
                    }
                }

                if (won) {
                    break;
                }
            }

            if (won) {
                break;
            }
        }

        if (won) {
            break;
        }
    }

    // Calculate final score
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (marked[winningBoard].grid[i][j] == 0) {
                sum += boards[winningBoard].grid[i][j];
            }
        }
    }

    cout << sum * winningDraw << endl;
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
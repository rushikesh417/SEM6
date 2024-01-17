//USING BRANCH AND BOUND

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class NQueens {
private:
    int N;
    vector<vector<int>> board;

public:
    NQueens(int size) : N(size), board(size, vector<int>(size, 0)) {}

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 1) return false;  // Check if there's a queen in the same column
            if ((col - (row - i) >= 0) && board[i][col - (row - i)] == 1) return false;  // Check left diagonal
            if ((col + (row - i) < N) && board[i][col + (row - i)] == 1) return false;  // Check right diagonal
        }
        return true;
    }

    bool solveNQueens() {
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int cost = -pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == N) {
                // All queens are placed successfully
                printSolution();
                return true;  // Uncomment to find only one solution
            }

            for (int c = 0; c < N; ++c) {
                if (isSafe(row, c)) {
                    board[row][c] = 1;  // Place queen

                    // Calculate the cost for the current state (number of conflicts)
                    int currentCost = cost + countConflicts(row, c);

                    pq.push({-currentCost, {row + 1, c}});
                    board[row][c] = 0;  // Remove queen
                }
            }
        }

        return false;  // No solution found
    }

    int countConflicts(int row, int col) const {
        int conflicts = 0;
        for (int i = 0; i < N; ++i) {
            if (board[i][col] == 1) conflicts++;  // Check column conflicts
            if ((col - (row - i) >= 0) && board[i][col - (row - i)] == 1) conflicts++;  // Check left diagonal conflicts
            if ((col + (row - i) < N) && board[i][col + (row - i)] == 1) conflicts++;  // Check right diagonal conflicts
        }
        return conflicts;
    }

    void printSolution() const {
        cout << "Solution:" << endl;
        for (const auto &row : board) {
            for (int cell : row) {
                cout << (cell ? "Q" : ".") << " ";
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }
};

int main() {
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;

    NQueens nQueens(N);
    nQueens.solveNQueens();

    return 0;
}

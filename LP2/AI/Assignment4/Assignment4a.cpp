#include <iostream>
#include <vector>

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

    bool solveNQueens(int row) {
        if (row == N) {
            // All queens are placed successfully
            printSolution();
            return true;  // Uncomment to find only one solution
        }

        for (int col = 0; col < N; ++col) {
            if (isSafe(row, col)) {
                board[row][col] = 1;  // Place queen

                // Recur to place the rest of the queens
                if (solveNQueens(row + 1)) {
                    return true;  // Uncomment to find only one solution
                }

                // If placing queen in the current position doesn't lead to a solution, backtrack
                board[row][col] = 0;  // Remove queen
            }
        }

        return false;  // No solution found
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
    nQueens.solveNQueens(0);

    return 0;
}

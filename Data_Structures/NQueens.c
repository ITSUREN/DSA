#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

// Print the solution board
void printSolution(int board[N][N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check column above
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queen problem
bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        printSolution(board);
        return true; // Return true to show at least one solution
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            // Recur to place queen in next row
            res = solveNQueens(board, row + 1) || res;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0};

    system("clear");
    if (!solveNQueens(board, 0))
        printf("No solution exists.\n");
    return 0;
}

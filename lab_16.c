#include <stdio.h>
#include <stdbool.h>

#define N 4 // Set the size of the chessboard to 4x4

// Function to print the solution
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve the N-Queen problem
bool solveNQUtil(int board[N][N], int col)
{
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing the queen in board[i][col] doesn't lead to a solution, then remove the queen
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQ()
{
    int board[N][N] = {0};

    if (!solveNQUtil(board, 0))
    {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}

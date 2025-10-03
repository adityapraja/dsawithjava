#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(int** board, int n);
bool isSafe(int** board, int row, int col, int n);
bool solveNQ(int** board, int row, int n);

int main() 
{
    int n;
    printf("Enter the number of queens (board size n): ");
    scanf("%d", &n);        //inputs the number of queens

    if (n <= 0) 
    {       //input error handling
        printf("Please enter a positive number for the board size.\n");
        return 1;
    }
    //allocates the memory for chess board using malloc
    int** board = (int**)malloc(n * sizeof(int*));
    if (board == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        board[i] = (int*)malloc(n * sizeof(int));
        if (board[i] == NULL) 
        {
            printf("Memory allocation failed.\n");
            for(int j = 0; j < i; j++) 
            {
                free(board[j]);
            }
            free(board);
            return 1;
        }
    }


    //initializes all the locations of board to 0
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            board[i][j] = 0;
        }
    }
    //if the solution doesnt exists this prints and calls the solving function
    if (solveNQ(board, 0, n) == false) 
    {
        printf("No solution exists for n = %d\n", n);
    }
    // after execution frees the allocated memory
    for (int i = 0; i < n; i++) 
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

//function to print the chessboard
void printBoard(int** board, int n) 
{
    static int solutionCount = 1;
    printf("Solution #%d:\n", solutionCount++);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//functions to check adjacents elements of queen
bool isSafe(int** board, int row, int col, int n) 
{
    int i, j;

    for (i = 0; i < row; i++) 
    {
        if (board[i][col] == 1) 
        {
            return false;
        }
    }

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }

    return true;
}


bool solveNQ(int** board, int row, int n) 
{
    //error handling
    if (row == n) 
    {
        printBoard(board, n);
        return true;
    }

    bool res = false;
    for (int col = 0; col < n; col++) 
    {
        //assigns the queens to a position by checking safe position
        if (isSafe(board, row, col, n)) 
        {

            board[row][col] = 1;

            res = solveNQ(board, row + 1, n) || res;    //recursively calls the solving function

            board[row][col] = 0;
        }
    }
    return res;
}



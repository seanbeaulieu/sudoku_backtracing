#include <stdio.h>

// only 9x9 for now
#define SIZE 9

// returns 1 if given number is valid for the given row and col index
// returns 0 if not
// feasible solution
int is_valid(int grid[SIZE][SIZE], int row, int col, int num) {
    int i, j;
    
    // check if num already exists in the same row
    for (i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    
    // check if num already exists in the same column
    for (i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    
    // check if num already exists in the same 3x3 subgrid

    // calculate the starting index of the subgrid row and column
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;

    // then check each index in the subgrid using a nested loop
    for (i = subgrid_row; i < subgrid_row + 3; i++) {
        for (j = subgrid_col; j < subgrid_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    
    // num is not present in row, col, or box 
    return 1;
}

// finds an empty cell in the sudoku grid
// takes in pointers to the row and col index
// returns 1 if an empty cell is found, 0 otherwise
int find_empty_cell(int grid[SIZE][SIZE], int *row, int *col) {

    // nested for loop to look for the nearest empty cell to (0, 0)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                // sets pointers to the cell index
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    // no cells are empty
    return 0;
}

// implement the backtracking algorithm
// returns 1 if a solution is found, 0 otherwise
int solve(int grid[SIZE][SIZE]) {
    int row, col;
    
    // find the next empty cell
    // pass in the memory addresses of row and col
    // picks a decision point
    // grid would be decision space here
    if (!find_empty_cell(grid, &row, &col)) {
        // no cells are empty, puzzle solved
        // solution
        return 1;
    }  
    
    // try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // checks if a number 1-9 is a valid spot for given empty spot in grid
        if (is_valid(grid, row, col, num)) {
            // set the spot in grid to the number
            // candidate
            grid[row][col] = num; 
            
            // call recursive function
            // partial solution
            if (solve(grid)) {  
                // return partial solution
                return 1;
            }
            
            // deadend, backtrack
            // reverse decision
            grid[row][col] = 0; 
        }
    }
    
    return 0;
}

// print the current grid 
void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // using grid from geekforgeeks
    int grid[SIZE][SIZE] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solve(grid)) {
        print_grid(grid);
    }

    return 0;
}
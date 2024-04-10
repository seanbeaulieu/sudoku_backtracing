# Sudoku Solver Using Backtracing 
    What is backtracing?

    Backtracing is a simple brute force algorithm that attempts to find solutions to problems by attempting incremental steps and removing the steps if they fail. One of the most common problems for this type of algorithm is Sudoku. While not the fastest algorithm to solve 9x9 Sudoku problems, it is an interesting application of depth-first search. 

    The algorithm works by first taking in a 2d array problem set, and then picks the closest empty cell next to (0,0). It will run a recursive loop where it will attempt to first put the value 1 in the cell, checking to see if that is a valid solution for the current cell, and if not, incrementing the value. If it is a valid solution, it will attempt to put a 1 into the next empty cell. If it ever reaches a cell where values 1-9 are all invalid solutions for that row, column, or subgrid, then it will instead return back to the previous cell, and increment that value, restarting the process.

    Time Complexity: worst case O(9^(2N))

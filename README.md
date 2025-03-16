# Skyscraper Puzzle Solver
This project is a successfully completed Rush01 from the 42 Network Piscine. It’s a Skyscraper Puzzle Solver that uses recursive backtracking to find solutions. This was a group project—I implemented the algorithm, while my two teammates handled the parsing.

## How to run the solver
Compile all .c files:
`cc *.c -o solver`

Run the program with the arguments in the following order: Top Bottom Left Right
`./program "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"`

The output for this example should be like this:
```
      3   2   1   4   2
   ++++++++++++++++++++++++
 2 +  3 | 2 | 5 | 1 | 4  + 2
 2 +  1 | 5 | 4 | 3 | 2  + 4
 4 +  2 | 1 | 3 | 4 | 5  + 1
 2 +  4 | 3 | 2 | 5 | 1  + 2
 1 +  5 | 4 | 1 | 2 | 3  + 3
   ++++++++++++++++++++++++
      1   2   5   2   2
```
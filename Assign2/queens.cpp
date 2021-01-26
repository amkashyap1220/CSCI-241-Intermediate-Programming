/**********************************************************
 * CSCI 241         Assignment 2      Spring 2021
 * @author Alexander Kashyap
 * @file queen.cpp
 * @version 1.0
 * Section: 1
 * Date Due: 1/28/2021
 * Purpose:  A program that finds a valid position for 8 queens on a board at once
 **********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

// board size
#define N 8

/**
 * Class queen solver
 *
 * This class controls the board output and the logic for the solution
 */
class queen_solver
{
private:
    bool board[N][N] = {{false}};

public:
    // Defining public class methods
    queen_solver() = default;
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution() const;
};


int main()
{
    // Initialinzing a board/solver
    queen_solver q;

    // Call for a solution, if one is gotten print it out
    if (q.place_queens())
        q.print_solution();
    else
        // This should only trigger if code breaks, there are solutions
        cout << "Error - no solution found\n";
    return 0;
}

/**
 * calls the recursive funtion to begin placing queens
 * @return boolean value if queens were placed corretly
 */
bool queen_solver::place_queens()
{
    return place_queen_in_row(0);
}

/**
 * attempts to place queens in all rows (main solution)
 * @return boolean value signaling if queen was place in ROW corretly
 */
bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= N)
        return true;

    // Loop through the row
    for (int col = 0; col < N; col++)
    {
        // If a position is safe, place a queen
        if (is_safe(row, col))
        {
            board[row][col] = true;

            // After any queen is placed attempt the next row
            if (place_queen_in_row(row + 1)) {
                // Base case #2 - All queens in rows below this one
                // have been successfully placed.
                return true;
            } else {
                // Remove the queen if no solution was found
                board[row][col] = false;
            }
        }
    }
    
    // Base case #3 - We were not able to place a queen anywhere in 
    // this row.
    return false;
}

/**
 * checks if a queen can be placed at a passed point in the array
 * @param row row of point to check
 * @param col column of point to check 
 */
bool queen_solver::is_safe(int row, int col) const {
    // Check the rows above this column. col stays the same, row varies
    // from row - 1 down to 0.
    for (int i = row - 1; i >= 0; i--) {  
        if (board[i][col]) {
            return false;
        }
    }

    // Check the left diagonal above this row. col varies from col - 1
    // down to 0, row varies from row - 1 down to 0.
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j]) {
            return false;
        }
        i--;
        j--;
    }

    // Check the right diagonal above this row. col varies from col + 1
    // up to 7, row varies from row - 1 down to 0.
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < N) {
        if (board[i][j]) {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

/**
 * Prints out the board
 */
void queen_solver::print_solution() const {
    cout << left;
    for (int i  = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                cout << setw(2) << "1";
            } else {
                cout << setw(2) << "0";
            }
        }
        cout << endl; 
    }
}
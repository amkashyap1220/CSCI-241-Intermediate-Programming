/**********************************************************
 * CSCI 241         Assignment 2      Spring 2021
 * @author Alexander Kashyap
 * @file hanoi.cpp
 * @version 1.0
 * Section: 1
 * Date Due: 1/28/2021
 * Purpose:  A program that solves the "towers of hanoi" problem using recursion
 **********************************************************/
#include <iostream>

using std::cout;
using std::endl;
using std::stoi;

// Function prototypes
void move(int n_disk, int src_peg, int dest_peg, int temp_peg);

int main(int argc, char * argv[]) { 

    // Checking to see if there are any arguments   

    if (argc == 1) {
        cout << "Missing argument!\n";
        cout << "Usage: hanoi number" << endl;
        exit(1);
    }

    // Checking if those arguments are numbers

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) { 
            cout << "Argument must be a number!\n";
            cout << "Usage: hanoi number" << endl;
            exit(1);
        }
    }

    // Define the number of disk to solve for and call the recursive function move

    int num_disk = stoi(argv[1]);
    move(num_disk, 1, 2, 3);

    return 0;
}

/**
 * This method prints to standard outout the moves that the program does
 * @param n_disk disk thats being moved
 * @param src_peg the source peg for the disk
 * @param dest_peg the destination peg for the disk;
 * @param temp_peg the temporary holding peg for the disk
 */
void move(int n_disk, int src_peg, int dest_peg, int temp_peg) {

    // Base case: there is only only disk left and you move it to the dest peg

    if (n_disk == 1) {
        cout << "1 " << src_peg << "->" << dest_peg << endl;
    } else {

        // 0therwise shift disks and print the moves they do and call the function on it self with the next disk to be moved

        move(n_disk - 1, src_peg, temp_peg, dest_peg);
        cout << n_disk << " " << src_peg << "->" << dest_peg << endl;
        move(n_disk - 1, temp_peg, dest_peg, src_peg);
    }
}
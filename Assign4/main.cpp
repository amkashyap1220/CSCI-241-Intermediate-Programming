/**********************************************************
 * CSCI 241         Assignment 4     Spring 2021
 * @author Alexander Kashyap
 * @file main.cpp
 * @version 1.0
 * Section: 1
 * Date Due: 2/11/2021
 * Z-id: z1926618  
 **********************************************************/
#include "simplesim.h"

/**
 * A program to simulate a fictional computer called the Simplesim
 */
int main()
{
    // Creating simple sim object
    simplesim s;

    // If loading succeeds, execute the loaded program
    if (s.load_program())
        s.execute_program();

    // output
    s.dump();

    return 0;
}

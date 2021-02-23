/**
 * @file main.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */
#include "bank.h"
#include "account.h"
#include <iostream>
using namespace std;

/**
 * @brief The purpose of this program is to create and print a small collection of bank accounts. As well as run some transactions on them.
 * 
 * @param argc Argument count
 * @param argv Arguments
 * @return int exit code
 */
int main(int argc, char* argv[])
{
    // Create a bank object, read in accounts, and process the transactions.
    bank chase;
    chase.read_accounts("accounts");
    chase.print();
    chase.process_transactions("transactions.txt");
    chase.print();
    exit(0);
}
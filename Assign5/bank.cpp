/**
 * @file bank.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */

#include "bank.h"
#include <fstream>
#include <iostream> // ?
using namespace std;

void bank::read_accounts(string filename)
{
    ifstream in_file;
    in_file.open(filename);
    if(!in_file)
    {
        perror("Error in open");
        exit(1);
    }

    while (in_file.read((char*) &accounts[accounts_count], sizeof(account)))
    {
        accounts_count++;
    }

    in_file.close();
}
void bank::process_transactions(string filename)
{
    ifstream in_file;
    in_file.open(filename);
    if (!in_file)
    {
        perror("Error in open");
        exit(1);
    }
    
    string date;
    //     Transaction Report

    // Date    Account      Type   Amount     New Balance

    // 08/19   1130034922   D       5500.00   *** Invalid account number ***
    // 08/19   5540853032   W        430.00    4420.75
    // 08/20   7415949234   D       3620.45    7359.09
    // 08/20   9858542030   W        130.00   11213.82
    // 08/20   1132264809   W       3275.23   *** Insufficient funds ***
    // 08/20   6379094723   W        250.00    2453.62

}

void bank::print() const
{
    cout << bank_name << endl;
    
}
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
int main(int argc, char* argv[])
{
    account alex;
    cout << alex.get_account_balance() << endl;
    alex.process_deposit(100);
    cout << alex.get_account_balance() << endl;
}
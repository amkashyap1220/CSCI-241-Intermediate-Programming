/**
 * @file bank.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */
#ifndef BANK_H
#define BANK_H

#include <string>
#include "account.h"

using std::string;

class bank
{
private:
    char bank_name[31] = "None";
    account accounts[20];
    int accounts_count = 0;
public:
    bank() = default;
    void read_accounts(string filename);
    void process_transactions(string filename);
    void print() const;
};

#endif
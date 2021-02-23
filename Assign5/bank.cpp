/**
 * @file bank.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */

#include <iomanip>
#include "bank.h"
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

// Function prototype
void swap(account *a, account *b);

/**
 * @brief Read in the account information from a file into the bank object
 * 
 * @param filename file to read accounts from
 */
void bank::read_accounts(string filename)
{
    ifstream in_file;
    in_file.open(filename);
    if (!in_file) // Error checking
    {
        perror("Error in open");
        exit(1);
    }

    in_file.read((char *)this, sizeof(bank));

    in_file.close();

    // Sort the accounts once we are done.
    selection_sort_account();
}

/**
 * @brief Process all of the transactions for the accounts from a file
 * 
 * @param filename file to read transaction information from
 */
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
    char account_number[11];
    char type;
    double amount;
    int index;

    // This Loop print out and processes all the transactions
    cout << "Transaction Report\n\nDate    Account      Type   Amount     New Balance\n\n";
    while (in_file >> date)
    {
        // Read in the information first
        in_file >> account_number;
        in_file >> type;
        in_file >> amount;

        // print out transaction information
        cout << setw(8) << left << date << setw(13) << account_number << setw(7) << type << right << fixed << setprecision(2) << setw(8) << amount;
        if ((index = binary_search_account(account_number)) == -1) // Error, account number not found
        {
            cout << "   *** Invalid account number ***" << endl;
        }
        else if (type == 'D')
        {
            accounts[index].process_deposit(amount);
            cout << setw(11) << accounts[index].get_account_balance() << endl;
        }
        else if (type == 'W')
        {
            if (accounts[index].process_withdrawal(amount))
            {
                cout << setw(11) << accounts[index].get_account_balance() << endl;
            }
            else
            {
                cout << "   *** Insufficient funds ***" << endl; // Error no enough money to withdrawl
            }
        }
    }
    cout << endl;
}

/**
 * @brief print out the bank object and its information
 * 
 */
void bank::print() const
{
    // Show all of the account listings
    cout << "Account Listing for " << bank_name << "\n\n";
    for (int i = 0; i < accounts_count; i++)
    {
        accounts[i].print();
        cout << endl;
    }
}

/**
 * @brief a binaray search over the accounts based on the account number
 * 
 * @param account_number the account that you are searching for
 * @return int the index in the accounts array that matches with the accounts number
 */
int bank::binary_search_account(char account_number[])
{
    int low = 0;
    int high = accounts_count - 1;
    int mid;

    // accounts are sorted, cut search area in half until we are left with the account index
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(account_number, accounts[mid].get_account_number()) == 0)
        {
            return mid;
        }
        else if (strcmp(account_number, accounts[mid].get_account_number()) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // Account not found
    return -1;
}

/**
 * @brief Sort the accounts based on their account numbers with the selection sort
 * 
 */
void bank::selection_sort_account()
{
    int min_index = 0;
    for (int i = 0; i < accounts_count; i++)
    {
        for (int j = i + 1; j < accounts_count; j++)
        {
            // To compare the two account numbers (cstrings) use strcmp
            if (strcmp(accounts[min_index].get_account_number(), accounts[j].get_account_number()) > 0)
            {
                min_index = j;
            }
        }
        swap(&accounts[i], &accounts[min_index]);
    }
}

/**
 * @brief swaps two accoounts in memory
 * 
 * @param a account to be swaped
 * @param b account 2 to be swaped
 */
void swap(account *a, account *b)
{
    account temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * @file account.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */

#include <iostream>
#include <iomanip>

#include "account.h"

using namespace std;

/**
 * @brief Return the account number for an account
 * 
 * @return const char* the account number
 */
const char *account::get_account_number() const
{
    return this->account_number;
}

/**
 * @brief Return the account balance for an account
 * 
 * @return double the account balance
 */
double account::get_account_balance() const
{
    return this->account_balance;
}

/**
 * @brief take a double deposit amount and add it to the balance for the bank account
 * 
 * @param deposit_amount the amount to be deposited
 */
void account::process_deposit(double deposit_amount)
{
    this->account_balance += deposit_amount;
}

/**
 * @brief take a double withdrawal amount. If the bank account's balance is less than the withdrawal amount, 
 * the member function should just return false. Otherwise, subtract the withdrawal amount from the balance 
 * of the bank account and return true.
 * 
 * @param withdrawal_amount the amount to be withdrawal from the account
 * @return true, bank account's balance is not less than the withdrawal amount
 * @return false, bank account's balance is less than the withdrawal amount
 */
bool account::process_withdrawal(double withdrawal_amount)
{
    if (this->account_balance < withdrawal_amount)
    {
        return false;
    }
    this->account_balance -= withdrawal_amount;
    return true;
}

/**
 * @brief print the values of the data members 
 * 
 */
void account::print() const
{
    cout << "Account Number: " << account_number << endl;
    cout << "Name: " << customer_name << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account_balance << endl;
    
}
// Random note - use insertion sort and then search
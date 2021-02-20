/**
 * @file account.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H
class account
{
private:
    char account_number[11];
    char customer_name[21] = "None";
    double account_balance = 0; 

public:
    account() = default; //?
    const char *get_account_number() const;
    double get_account_balance() const; 
    void process_deposit(double deposit_amount);
    bool process_withdrawal(double withdrawal_amount);
    void print() const;
};
#endif

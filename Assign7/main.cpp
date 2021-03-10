//*******************************************************************
//
//  inpost_main.cpp
//  CSCI 241 Assignment 7
//
//  Created by name (z-ID)
//
//*******************************************************************

#include <iostream>
#include <string>
#include "inpost.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

/**
 * Reads a series of infix strings from standard input, converts them
 * to postfix, and prints them.
 *
 * @return Returns 0 upon successful completion.
 ********************************************************************/
int main()
{
    string infix;
    string postfix;

    while (getline(cin, infix))
    {
        cout << "  infix: " << infix << endl;
        postfix = convert(infix);
        cout << "postfix: " << postfix << endl << endl;
    }

    return 0;
}

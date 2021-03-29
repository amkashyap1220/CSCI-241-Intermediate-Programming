//*****************************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 9
//  Created by Alexander Kashyap z1926618
//
//*****************************************************************************

#include "inpost.h"
#include "mystack.h"
#include <cctype>
#include <string>
#include <map>
#include <list>

using namespace std;

/**
 * @brief converts the infix expression into an equivalent postfix expression
 * 
 * @param infix infix expression to convert
 * @return string postfix expression
 */
string convert(const string& infix)
{
    // map that contains the oporators as keys and their prio (higher means > prio) as the values
    map<char, int> map = { { '~', 3 }, { '^', 3 }, { '*', 2 }, { '/', 2 }, { '+', 1 }, { '-', 1 } };

    string postfix = "";
    mystack stack;

    // Loop through each char in the infix string and run it throught the conversion algo to postfix
    for (size_t i = 0; i < infix.length(); i++)
    {
        if (islower(infix[i]))
        {
            // This is a variable
            postfix += infix[i];
            postfix += ' ';
        }
        else if (isdigit(infix[i]))
        {
            // This is a num (must read in the whole num then add the space)
            while (i < infix.length() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += ' ';
        }
        else if (infix[i] == '(')
        {
            stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            // conversion for inside the ( ) in infix
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            if (stack.top() == '(')
            {
                stack.pop();
            }
        }
        else if (infix[i] != ' ') // lastly, if its not a space it must be an operator
        {
            // This is an operator
            while (!stack.empty() && map[infix[i]] <= map[stack.top()])
            {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.push(infix[i]);
            
        }
    }

    // finally emptying all of the rest of the stack
    while (!stack.empty())
    {
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }

    //removing the trailing ' '
    postfix.pop_back();
    return postfix;
}
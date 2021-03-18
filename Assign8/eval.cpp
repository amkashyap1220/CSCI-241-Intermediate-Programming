/**
 * @file eval.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-18
 * 
 * Assignment 8
 * Course: CSCI 241
 * Section: 1
 */
#include "eval.h"
#include "mystack.h"
#include <string>
#include <sstream>
#include <cctype>
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief evauluates a passed postfix expression
 * 
 * @param postfix expression to be evaluated
 * @return int the answer to the expression
 */
int evaluate(const string& postfix)
{
    string op;
    stringstream ss = stringstream(postfix);

    mystack eval_stack;

    // loop through each element of the postfix expression
    while (ss >> op)
    {
        // compare each element to decide where to run an operation or to push onto stack
        if(isdigit(op[0]))
        {
            eval_stack.push(stoi(op));
        }
        else if (isalpha(op[0]))
        {
            eval_stack.push(int(op[0] - 'a'));
        }
        else if (op == "~")
        {
            // negation
            int temp = eval_stack.top() * -1;
            eval_stack.pop();
            eval_stack.push(temp);
        }
        else 
        {
            // for binary operators get a left and right side of operator
            int r = eval_stack.top();
            eval_stack.pop();
            int l = eval_stack.top();
            eval_stack.pop();
            
            // now check what that operator is and apply it
            if (op == "+")
            {
                eval_stack.push(l + r);
            } 
            else if (op == "-")
            {
                eval_stack.push(l - r);
            } 
            else if (op == "/")
            {
                if (r == 0)
                {
                    cout << "*** Division by 0 ***" << endl;
                    return 0;
                }
                eval_stack.push(l / r);
            } 
            else if (op == "*")
            {
                eval_stack.push(l * r);
            } 
            else if (op == "^")
            {
                eval_stack.push(pow(l, r));
            } 
        }
    }

    // return the answer
    return eval_stack.top();;
}
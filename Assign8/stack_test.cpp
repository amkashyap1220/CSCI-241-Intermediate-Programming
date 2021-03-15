//*************************************************************************
//  stack_test.cpp
//  CSCI 241 Assignment 8
//
//  Created by Kurt McMahon (t90kjm1).
//*************************************************************************

#include <iostream>
#include "mystack.h"

using namespace std;

int main()
{
    char letters[] = "abcdef";
    int numbers[] = {32, 18, 5, 24};
    const mystack s1;
    
    cout << "Default constructor\n\n";
    
    cout << "Testing empty():          ";
    cout << ((s1.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s1.size() == 0) ? "SUCCESS\n" : "failure\n");
    
    cout << "\npush(), top(), and pop()\n\n";

    mystack s2;
    int i;

    bool correct = true;
    for (i = 0; i < 4; i++)
    {
        s2.push(numbers[i]);
        if (numbers[i] != s2.top())
            correct = false;
        if ((int) s2.size() != i+1)
            correct = false;
    }

    cout << "Testing push() and top(): ";
    cout << ((correct) ? "SUCCESS\n" : "failure\n");
    cout << "Testing empty():          ";
    cout << ((!s2.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s2.size() == 4) ? "SUCCESS\n" : "failure\n");
    cout << "Testing top():            ";
    cout << ((s2.top() == numbers[3]) ? "SUCCESS\n" : "failure\n");

    correct = true;
    for (i = 0; i < 6; i++)
    {
        s2.push(letters[i]);
        if (letters[i] != s2.top())
            correct = false;
        if ((int) s2.size() != i+5)
            correct = false;
    }

    cout << "Testing push() and top(): ";
    cout << ((correct) ? "SUCCESS\n" : "failure\n");
    cout << "Testing empty():          ";
    cout << ((!s2.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s2.size() == 10) ? "SUCCESS\n" : "failure\n");
    cout << "Testing top():            ";
    cout << ((s2.top() == letters[5]) ? "SUCCESS\n" : "failure\n");

    mystack s3(s2);
    
    correct = true;
    for (i = 5; i >= 0; i--)
    {
        if (letters[i] != s2.top())
            correct = false;
        
        s2.pop();
    }

    for (i = 3; i >= 0; i--)
    {
        if (numbers[i] != s2.top())
            correct = false;
        
        s2.pop();
    }

    cout << "Testing top() and pop():  ";
    cout << ((correct) ? "SUCCESS\n" : "failure\n");

    cout << "\nCopy constructor\n\n";
    
    cout << "Testing empty():          ";
    cout << ((!s3.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s3.size() == 10) ? "SUCCESS\n" : "failure\n");
    cout << "Testing top():            ";
    cout << ((s3.top() == letters[5]) ? "SUCCESS\n" : "failure\n");

    mystack s4;
    s4 = s3 = s4 = s3;
    
    cout << "\nCopy assignment operator\n\n";
    
    cout << "Testing empty():          ";
    cout << ((!s3.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s3.size() == 10) ? "SUCCESS\n" : "failure\n");
    cout << "Testing top():            ";
    cout << ((s3.top() == letters[5]) ? "SUCCESS\n" : "failure\n");

    cout << "Testing empty():          ";
    cout << ((!s4.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s4.size() == 10) ? "SUCCESS\n" : "failure\n");
    cout << "Testing top():            ";
    cout << ((s4.top() == letters[5]) ? "SUCCESS\n" : "failure\n");

    correct = true;
    for (i = 5; i >= 0; i--)
    {
        if (letters[i] != s4.top())
            correct = false;
        
        s4.pop();
    }
    
    for (i = 3; i >= 0; i--)
    {
        if (numbers[i] != s4.top())
            correct = false;
        
        s4.pop();
    }
    
    cout << "Testing top() and pop():  ";
    cout << ((correct) ? "SUCCESS\n" : "failure\n");

    const mystack& s5 = s3;
    
    cout << "Testing empty():          ";
    cout << ((!s5.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s5.size() == 10) ? "SUCCESS\n" : "failure\n");
    cout << "Testing top():            ";
    cout << ((s5.top() == letters[5]) ? "SUCCESS\n" : "failure\n");

    s3.clear();

    cout << "\nclear()\n\n";

    cout << "Testing empty():          ";
    cout << ((s5.empty()) ? "SUCCESS\n" : "failure\n");
    cout << "Testing size():           ";
    cout << ((s5.size() == 0) ? "SUCCESS\n" : "failure\n");

    return 0;
}

//*******************************************************************
// 
//  assign10.cpp
//  CSCI 241 Assignment 10
//
//  Created by name(s) and z-ID(s)
//
//*******************************************************************

#include <iostream>
#include <stdexcept>
#include "mylist.h"

using std::cout;
using std::endl;
using std::underflow_error;

int main()
{
    cout << "*** Testing default constructor ***\n\n";
    
    mylist<int> l1;
    
    cout << "*** Testing size(), operator<<(), and empty() with empty list ***\n\n";
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l1 is " << ((l1.empty()) ? "empty\n\n" : "not empty\n\n");

    cout << "*** Testing push_back() into empty list ***\n\n";
    
    l1.push_back(40);
    
    cout << "*** Testing size(), operator<<(), and empty() with non-empty list ***\n\n";
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l1 is " << ((l1.empty()) ? "empty\n\n" : "not empty\n\n");
    
    cout << "*** Testing push_back() into non-empty list ***\n\n";
    
    l1.push_back(50);
    l1.push_back(60);
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl << endl;
    
    mylist<char> l2;
    
    cout << "*** Testing push_front() into empty list ***\n\n";
    
    l2.push_front('c');
    
    cout << "l2 (size " << l2.size() << "): " << l2 << endl << endl;
    
    cout << "*** Testing push_front() into non-empty list ***\n\n";
    
    l2.push_front('b');
    l2.push_front('a');
    
    cout << "l2 (size " << l2.size() << "): " << l2 << endl << endl;
    
    cout << "*** Testing push_front() and push_back() ***\n\n";
    
    l1.push_front(30);
    l1.push_front(20);
    l1.push_front(10);
    
    l2.push_back('d');
    l2.push_back('e');
    l2.push_back('f');
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l2 (size " << l2.size() << "): " << l2 << endl << endl;
    
    cout << "*** Testing read version of front() and back() ***\n\n";
    
    cout << "l1 front: " << l1.front() << endl;
    cout << "l1 back: " << l1.back() << endl << endl;
    
    cout << "*** Testing write version of front() and back() ***\n\n";
    
    l1.front() = 5;
    l1.back() = 65;
    
    cout << "l1 front: " << l1.front() << endl;
    cout << "l1 back: " << l1.back() << endl << endl;
    
    cout << "*** Testing pop_back() ***\n\n";
    
    l2.pop_back();
    l2.pop_back();
    
    cout << "l2 (size " << l2.size() << "): " << l2 << endl << endl;
    
    cout << "*** Testing pop_front() ***\n\n";
    
    l2.pop_front();
    l2.pop_front();
    
    cout << "l2 (size " << l2.size() << "): " << l2 << endl << endl;
    
    cout << "*** Testing pop to empty ***\n\n";
    
    l2.pop_back();
    l2.pop_front();
    
    cout << "l2 (size " << l2.size() << "): " << l2 << endl << endl;
    
    cout << "*** Testing copy constructor ***\n\n";
    
    mylist<int> l3 = l1;
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l3 (size " << l3.size() << "): " << l3 << endl << endl;
    
    cout << "*** Testing for shallow copy ***\n\n";
    
    l1.front() = 10;
    l1.back() = 60;
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l3 (size " << l3.size() << "): " << l3 << endl << endl;
    
    cout << "*** Testing copy assignment operator ***\n\n";
    
    l1.push_back(70);
    l1.push_back(80);
    
    l3 = l1;
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l3 (size " << l3.size() << "): " << l3 << endl << endl;
    
    cout << "*** Testing for shallow copy ***\n\n";
    
    l1.push_back(90);
    l3.pop_front();
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l3 (size " << l3.size() << "): " << l3 << endl << endl;
    
    cout << "*** Testing self-assignment ***\n\n";
    
    l1 = l1;
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl << endl;
    
    cout << "*** Testing chained assignment ***\n\n";
    
    mylist<int> l4;
    
    l4 = l3 = l1;
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl;
    cout << "l3 (size " << l3.size() << "): " << l3 << endl;
    cout << "l4 (size " << l4.size() << "): " << l4 << endl << endl;
    
    cout << "*** Testing equality operator ***\n\n";
    
    cout << "l1 and l4 are " << ((l1 == l4) ? "equal\n" : "not equal\n");
    
    l3.back() = -8;
    
    cout << "l1 and l3 are " << ((l1 == l3) ? "equal\n" : "not equal\n");
    
    l4.pop_front();
    
    cout << "l1 and l4 are " << ((l1 == l4) ? "equal\n\n" : "not equal\n\n");
    
    cout << "*** Testing less than operator ***\n\n";
    
    cout << "l1 is " << ((l1 < l4) ? "less than" : "not less than") << " l4\n";
    cout << "l4 is " << ((l4 < l1) ? "less than" : "not less than") << " l1\n";
    cout << "l1 is " << ((l1 < l1) ? "less than" : "not less than") << " l1\n";
    cout << "l1 is " << ((l1 < l3) ? "less than" : "not less than") << " l3\n";
    cout << "l3 is " << ((l3 < l1) ? "less than" : "not less than") << " l1\n";
    
    l3.pop_back();
    
    cout << "l1 is " << ((l1 < l3) ? "less than" : "not less than") << " l3\n";
    cout << "l3 is " << ((l3 < l1) ? "less than" : "not less than") << " l1\n\n";
    
    cout << "*** Testing clear() ***\n\n";
    
    l1.clear();
    
    cout << "l1 (size " << l1.size() << "): " << l1 << endl << endl;
    
    cout << "*** Testing for const correctness ***\n\n";
    
    const mylist<int>& r4 = l4;
    
    cout << "l4 (size " << r4.size() << "): " << r4 << endl;
    cout << "l4 is " << ((r4.empty()) ? "empty\n" : "not empty\n");
    cout << "l4 front: " << r4.front() << endl;
    cout << "l4 back: " << r4.back() << endl;
    cout << "l4 and l1 are " << ((r4 == l1) ? "equal\n" : "not equal\n");
    cout << "l4 is " << ((r4 < l3) ? "less than" : "not less than") << " l3\n";
    cout << "l4 is " << ((r4 < l1) ? "less than" : "not less than") << " l1\n";
    cout << "l1 is " << ((l1 < r4) ? "less than" : "not less than") << " l4\n\n";
    
    l4.clear();
    
    cout << "*** Testing exception handling ***\n\n";

    try
    {
        cout << l4.front() << endl;
    }
    catch (underflow_error& e)
    {
        cout << "Caught "<< e.what() << endl;
    }

    try
    {
        cout << l4.back() << endl;
    }
    catch (underflow_error& e)
    {
        cout << "Caught "<< e.what() << endl;
    }

    try
    {
        l4.pop_front();
    }
    catch (underflow_error& e)
    {
        cout << "Caught "<< e.what() << endl;
    }

    try
    {
        l4.pop_back();
    }
    catch (underflow_error& e)
    {
        cout << "Caught "<< e.what() << endl;
    }

    try
    {
        cout << r4.front() << endl;
    }
    catch (underflow_error& e)
    {
        cout << "Caught "<< e.what() << endl;
    }

    try
    {
        cout << r4.back() << endl;
    }
    catch (underflow_error& e)
    {
        cout << "Caught "<< e.what() << endl;
    }

    return 0;
}

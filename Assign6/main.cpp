//***************************************************************************
//
//  main.cpp
//  CSCI 241 Assignment 6
//
//  Created by name(s) and z-ID(s)
//
//***************************************************************************

#include <iostream>
#include <iomanip>
#include <tuple>
#include "complex.h"

using std::cin;
using std::cout;
using std::endl;
using std::get;
using std::tuple;

int main()
{
    cout << "Testing constructor... ";
    complex c1(23, 34);
    const complex c4(3, 4);

    cout << "done\n";  
    cout << "Testing default constructor... ";
   
    complex c2;
    complex c3;
   
    cout << "done\n\n";
   
    cout << "Testing stream insertion operator and constructors...\n";
   
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl << endl;

    cout << "Testing get methods...\n";
   
    cout << "Real part of c4 = " << c4.get_real() << endl;
    cout << "Imaginary part of c4 = " << c4.get_imaginary() << endl;
   
    tuple<double, double> result = c4.get_complex();

    cout << "Real part of c4 = " << get<0>(result) << endl;
    cout << "Imaginary part of c4 = " << get<1>(result) << endl << endl;
   
    cout << "Testing set methods...\n";
   
    c2.set_complex(3.7, 2.5);
    cout << "New value of c2 = " << c2 << endl;
    c2.set_real(-1.4);
    cout << "New value of c2 = " << c2 << endl;  
    c2.set_imaginary(83);  
    cout << "New value of c2 = " << c2 << endl << endl;
   
    cout << "Testing stream extraction operator...\n";
   
    cout << "Enter a complex number in the form (a, b) ";
    cin >> c2;
    cout << "New value of c2 = " << c2 << endl << endl;
   
    cout << "Testing addition operator...\n";
   
    c3 = c1 + c4;
    cout << "c3 = " << c3 << endl;
    cout << c4 << " + " << c1 << " = " << c4 + c1 << endl;
    cout << c4 << " + " << c4 << " = " << c4 + c4 << endl << endl;

    cout << "Testing multiplication operator...\n";

    c3 = c1 * c4;
    cout << "c3 = " << c3 << endl;
    cout << c4 << " * " << c1 << " = " << c4 * c1 << endl;  
    cout << c4 << " * " << c4 << " = " << c4 * c4 << endl << endl;  

    cout << "Testing equality operator...\n";

    cout << c1 << " and " << c3;
    (c1 == c3) ? cout << " are equal\n" : cout << " are not equal\n";

    const complex c5(3, 4);
    cout << c4 << " and " << c5;
    (c4 == c5) ? cout << " are equal\n" : cout << " are not equal\n";
      
    return 0;
}


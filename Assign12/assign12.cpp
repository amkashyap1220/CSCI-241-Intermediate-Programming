/******************************************************************************************************
 * @file assign12.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-15
 * Assignment 12
 * Due 2021-04-22
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{

    // Declare either an array or a standard library vector of pointers to shape objects.
    vector<shape*> array;

    // Dynamically create some circles, rectangles, and triangles (at least two of each). After creating each object, add it to the array or vector.
    rectangle* rect1 = new rectangle("green", 6, 7);
    rectangle* rect2 = new rectangle("blue", 2, 1);
    array.push_back(rect1);
    array.push_back(rect2);

    
    circle* circ1 = new circle("red", 5);
    circle* circ2 = new circle("grey", 13);
    array.push_back(circ1);
    array.push_back(circ2);

    triangle* tri1 = new triangle("teal", 51, 41);
    triangle* tri2 = new triangle("yellow", 42, 20);
    array.push_back(tri1);
    array.push_back(tri2);

    // Loop through the array or vector of shape pointers and call the print() method for each of them.
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i]->print();
    }

    // Loop through the array or vector of shape pointers again and call the print() method for each of the circle objects in the array or vector.
    for (size_t i = 0; i< array.size(); i++)
    {
        circle* cir = dynamic_cast<circle*>(array[i]);
        if (cir != nullptr)
        {
            cir->print();
        }
    }

    // Loop through the list of shape pointers one more time and delete each object.
    for (size_t i = 0; i < array.size(); i++)
    {
        array.pop_back();
    }
}
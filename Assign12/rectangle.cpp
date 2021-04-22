/******************************************************************************************************
 * @file rectangle.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-22
 * Assignment 12
 * Due 2021-04-22
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#include "rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************************************
 * Constructor for Rectangle
 * @param color color of the shape
 * @param height height of rectangle
 * @param width width of rectangle
******************************************************************************************************/
rectangle::rectangle(const string &color, int height, int width) : shape(color)
{
    this->height = height;
    this->width = width;
}

/******************************************************************************************************
 * Returns the area of a rectangle object
 * @return double 
******************************************************************************************************/
double rectangle::get_area() const
{
    return height * width;
}

/******************************************************************************************************
 * Prints out the rectangles information
******************************************************************************************************/
void rectangle::print() const
{
    shape::print();
    cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}


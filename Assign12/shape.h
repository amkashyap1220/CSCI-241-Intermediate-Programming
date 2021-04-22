/******************************************************************************************************
 * @file shape.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-22
 * Assignment 12
 * Due 2021-04-22
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using std::string;

class shape
{
private:
    string color;

public:
    shape() = default;
    shape(const string &color); // This will only be invoked through its children
    virtual ~shape();           // Needed for compiler, will give warning otherwise
    virtual void print() const;

    virtual double get_area() const = 0; // Pure virtual method
};
#endif
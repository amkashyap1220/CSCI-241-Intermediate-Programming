/******************************************************************************************************
 * @file triangle.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-22
 * Assignment 12
 * Due 2021-04-22
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class triangle : public shape
{
private:
    int height;
    int base;
public:
    triangle() = default;
    triangle(const string &color, int height, int base);

    virtual double get_area() const;
    virtual void print() const;
};

#endif
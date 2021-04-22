/******************************************************************************************************
 * @file circle.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-22
 * Assignment 12
 * Due 2021-04-22
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle : public shape
{
private:
    int radius;
public:
    circle() = default;
    circle(const string &color, int radius);

    virtual void print() const;
    virtual double get_area() const;
};
#endif
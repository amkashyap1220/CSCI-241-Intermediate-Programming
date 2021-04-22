/******************************************************************************************************
 * @file rectangle.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-22
 * Assignment 12
 * Due 2021-04-22
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
private:
    int height;
    int width;
public:
    rectangle() = default;
    rectangle(const string &color, int height, int width);

    virtual double get_area() const;
    virtual void print() const;
};

#endif
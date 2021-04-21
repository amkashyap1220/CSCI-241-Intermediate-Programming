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
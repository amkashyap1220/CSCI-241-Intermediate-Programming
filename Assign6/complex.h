/**
 * @file bank.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */
#ifndef COMPLEX_H
#define COMPLEX_H
#include <tuple>

/**
 * @brief The complex class represents a complex number as an ordered pair
 * 
 */
class complex
{
private:
    double real_part = 0;
    double imaginary_part = 0;

public:
    complex(double real_part, double imaginary_part);
    complex() = default;
    void set_complex(double real_part, double imaginary_part);
    std::tuple<double, double> get_complex() const;

};

#endif
/**
 * @file bank.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-04
 * 
 * Assignment 6
 * Course: CSCI 241
 * Section: 1
 */
#ifndef COMPLEX_H
#define COMPLEX_H
#include <tuple>
#include <iostream>

using std::ostream;
using std::istream;

/**
 * @brief The complex class represents a complex number as an ordered pair
 * 
 */
class complex
{
    friend istream& operator>>(istream& lhs, complex& rhs);
    friend ostream& operator<<(ostream& lhs, const complex& rhs);

private:
    double real_part = 0;
    double imaginary_part = 0;

public:
    complex(double real_part, double imaginary_part);
    complex() = default;
    void set_complex(double real_part, double imaginary_part);
    std::tuple<double, double> get_complex() const;
    void set_real(double real_part);
    double get_real() const;
    void set_imaginary(double imaginary_part);
    double get_imaginary() const;

    complex operator+(const complex& rhs) const;
    complex operator*(const complex& rhs) const;
    bool operator==(const complex& rhs) const;

};

#endif
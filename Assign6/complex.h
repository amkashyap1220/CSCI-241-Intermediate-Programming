/**
 * @file complex.h
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
    // overloaded operators as friends
    friend istream& operator>>(istream& lhs, complex& rhs);
    friend ostream& operator<<(ostream& lhs, const complex& rhs);

private:
    // private data members, the parts of the complex #
    double real_part = 0;
    double imaginary_part = 0;

public:
    // constructors
    complex(double real_part = 0.0, double imaginary_part = 0.0);

    // set's and get's
    void set_complex(double real_part, double imaginary_part);
    void set_imaginary(double imaginary_part);
    void set_real(double real_part);
    std::tuple<double, double> get_complex() const;
    double get_real() const;
    double get_imaginary() const;

    // operator overloads for arithmetic and ==
    complex operator+(const complex& rhs) const;
    complex operator*(const complex& rhs) const;
    bool operator==(const complex& rhs) const;

};

#endif
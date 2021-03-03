/**
 * @file bank.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-04
 * 
 * Assignment 6
 * Course: CSCI 241
 * Section: 1
 */

#include "complex.h"
#include <tuple>
#include <iostream>

using namespace std;
/**
 * @brief Construct a new complex object
 * 
 * @param real_part the real portion of the complex #
 * @param imaginary_part the imaginary part of the complex #
 */
complex::complex(double real_part, double imaginary_part)
{
    this->real_part = real_part;
    this->imaginary_part = imaginary_part;
}

/**
 * @brief sets the values of the complex number
 * 
 * @param real_part the real portion of the complex #
 * @param imaginary_part the imaginary part of the complex #
 */
void complex::set_complex(double real_part, double imaginary_part)
{
    this->real_part = real_part;
    this->imaginary_part = imaginary_part;
}

/**
 * @brief gets the complex number a returns it
 * 
 * @return std::tuple<double, double> returns the complex number as a tuple
 */
std::tuple<double, double> complex::get_complex() const
{
    std::tuple<double, double> toReturn(this->real_part, this->imaginary_part);
    return toReturn;
}

/**
 * @brief sets the real part of a complex #
 * 
 * @param real_part the real part
 */
void complex::set_real(double real_part)
{
    this->real_part = real_part;
}

/**
 * @brief Get the real part of a complex #
 * 
 * @return double the real part
 */
double complex::get_real() const
{
    return this->real_part;
}

/**
 * @brief sets the imaginary part of a complex #
 * 
 * @param imaginary_part the imaginary_part
 */
void complex::set_imaginary(double imaginary_part)
{
    this->imaginary_part = imaginary_part;
}

/**
 * @brief gets the imaginary part of a number
 * 
 * @return double the imaginary part
 */
double complex::get_imaginary() const
{
    return this->imaginary_part;
}

/**
 * @brief operator overload for +, adds two complex numbers together
 * 
 * @param rhs the "right hand side" complex number to be added with the complex 
 * @return complex the sum of 2 compelx #'s
 */
complex complex::operator+(const complex &rhs) const
{
    complex result;

    result.real_part = this->real_part + rhs.real_part;
    result.imaginary_part = this->imaginary_part + rhs.imaginary_part;

    return result;
}

complex complex::operator*(const complex &rhs) const
{
    complex result;

    result.real_part = (this->real_part * rhs.real_part) - (this->imaginary_part * rhs.imaginary_part);
    result.imaginary_part = (this->real_part * rhs.imaginary_part) + (this->imaginary_part * rhs.real_part);

    return result;
}

bool complex::operator==(const complex &rhs) const
{
    if (rhs.imaginary_part != this->imaginary_part)
        return false;
    if (rhs.real_part != this->real_part)
        return false;
    return true;
}

ostream &operator<<(ostream &os, const complex &rhs)
{
    os << "(" << rhs.real_part << ", " << rhs.imaginary_part << ")";
    return os;
}

istream &operator>>(istream &is, complex &rhs)
{
    char unused;

    is >> unused;
    is >> rhs.real_part;
    is >> unused;
    is >> rhs.imaginary_part;
    is >> unused;

    return is;
}
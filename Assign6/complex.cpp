/**
 * @file complex.cpp
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
    // create a tuple object
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

    // addition logic
    result.real_part = this->real_part + rhs.real_part;
    result.imaginary_part = this->imaginary_part + rhs.imaginary_part;

    return result;
}

/**
 * @brief operator overload for *
 * 
 * @param rhs the right hand operand
 * @return complex the product of 2 complex #
 */
complex complex::operator*(const complex &rhs) const
{
    complex result;

    // * logic for complex
    result.real_part = (this->real_part * rhs.real_part) - (this->imaginary_part * rhs.imaginary_part);
    result.imaginary_part = (this->real_part * rhs.imaginary_part) + (this->imaginary_part * rhs.real_part);

    return result;
}

/**
 * @brief operator overload for equality, determines if 2 complex #'s are =
 * 
 * @param rhs the right hand side of the operand
 * @return true complex # are =
 * @return false complex # are not =
 */
bool complex::operator==(const complex &rhs) const
{
    // checks if both parts of the complex are =
    if (rhs.imaginary_part != this->imaginary_part)
        return false;
    if (rhs.real_part != this->real_part)
        return false;
    return true;
}

/**
 * @brief prints a complex number
 * 
 * @param os stream object
 * @param rhs complex number to be printed
 * @return ostream& the ostream object reference for output
 */
ostream &operator<<(ostream &os, const complex &rhs)
{
    // print out in (x, y)
    os << "(" << rhs.real_part << ", " << rhs.imaginary_part << ")";
    return os;
}

/**
 * @brief reads in a number to complex
 * 
 * @param is input stream object reference
 * @param rhs the compelex reference object we are going to read into
 * @return istream& the input stream object back for casscading
 */
istream &operator>>(istream &is, complex &rhs)
{
    // read in from (x, y)
    char unused;

    is >> unused;
    is >> rhs.real_part;
    is >> unused;
    is >> rhs.imaginary_part;
    is >> unused;

    return is;
}
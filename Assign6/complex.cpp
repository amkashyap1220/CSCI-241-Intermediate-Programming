/**
 * @file bank.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @date 2021-02-18
 * 
 * Assignment 5
 * Course: CSCI 241
 * Section: 1
 */

#include "complex.h"
#include <tuple>

complex::complex(double real_part, double imaginary_part)
{

}
    
void complex::set_complex(double real_part, double imaginary_part)
{

}

std::tuple<double, double> complex::get_complex() const
{
    std::tuple<double, double> toReturn = (this->real_part, this->imaginary_part);
    return toReturn;
}
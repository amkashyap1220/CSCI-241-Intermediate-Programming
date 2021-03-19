/**
 * @file mystack.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-11
 * 
 * Assignment 7
 * Course: CSCI 241
 * Section: 1
 */

#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstdlib>

class mystack
{

private:
    char *stack_array_pointer = nullptr;
    size_t stack_capacity = 0;
    size_t stack_size = 0;

public:
    mystack() = default;
    mystack(const mystack &x);
    ~mystack();
    mystack &operator=(const mystack &x);
    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    void clear();
    void reserve(size_t n);
    const char &top() const;
    void push(char value);
    void pop();
};

#endif
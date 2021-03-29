//*****************************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 9
//  Created by Alexander Kashyap z1926618
//
//*****************************************************************************

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
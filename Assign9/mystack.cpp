/**
 * @file mystack.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-11
 * 
 * Assignment 7
 * Course: CSCI 241
 * Section: 1
 */
#include <cstdlib>
#include "mystack.h"

/**
 * @brief copy constuctor for the mystack object
 * 
 * @param cpy the stack to copy from
 */
mystack::mystack(const mystack &cpy)
{
    stack_size = cpy.stack_size;
    stack_capacity = cpy.stack_capacity;

    // Avoiding shallow copies
    if (stack_capacity == 0)
    {
        stack_array_pointer = nullptr;
    }
    else
    {
        stack_array_pointer = new char[cpy.stack_capacity];
        for (size_t i = 0; i < stack_size; i++)
        {
            stack_array_pointer[i] = cpy.stack_array_pointer[i];
        }
    }
}

/**
 * @brief Destroy the mystack object
 */
mystack::~mystack()
{
    delete[] stack_array_pointer;
}

/**
 * @brief overloaded copy assignment operator for mystack
 * 
 * @param other other stack to copy from
 * @return mystack& a pointer to this mystack object for cascading assignment;
 */
mystack &mystack::operator=(const mystack &other)
{
    // 1 Check for self-assignment
    if (this != &other)
    {
        // 2 Delete the dynamic data members
        delete[] stack_array_pointer;
        // 3 Copy all non-dynamic data members
        stack_size = other.stack_size;
        stack_capacity = other.stack_capacity;
        // 4 allocate same dynamic storage
        if (stack_capacity == 0)
        {
            stack_array_pointer = nullptr;
        }
        else
        {
            stack_array_pointer = new char[other.stack_capacity];
            // 5 copy over the contents for the array
            for (size_t i = 0; i < stack_size; i++)
            {
                stack_array_pointer[i] = other.stack_array_pointer[i];
            }
        }

    }
    return *this;
}

/**
 * @brief returns the mystack capacity
 * 
 * @return size_t capacity
 */
size_t mystack::capacity() const
{
    return stack_capacity;
}

/**
 * @brief returns the stack size
 * 
 * @return size_t size
 */
size_t mystack::size() const
{
    return stack_size;
}

/**
 * @brief checks if the stack is empty
 * 
 * @return true if the stack is empty
 * @return false if the stack is not
 */
bool mystack::empty() const
{
    return (stack_size == 0);
}

/**
 * @brief sets the stack size back to 0
 * 
 */
void mystack::clear()
{
    stack_size = 0;
}

/**
 * @brief modifies an object's stack capacity
 * 
 * @param n capacity to set stack to
 */
void mystack::reserve(size_t n)
{
    if (n <= stack_capacity)
    {
        return;
    }
    stack_capacity = n;
    // creating the new dynamic storage
    char* temp = new char[n];
    for (size_t i = 0; i < stack_size; i++)
    {
        temp[i] = stack_array_pointer[i];
    }
    // cleaning up the old dynamic storage
    delete[] stack_array_pointer;
    stack_array_pointer = temp;

}

/**
 * @brief returns the top of the stack
 * 
 * @return const char& the top value in the stack
 */
const char &mystack::top() const
{
    return stack_array_pointer[stack_size - 1];
}

/**
 * @brief push on a new item to the stack
 * 
 * @param value the item to be added to the stack
 */
void mystack::push(char value)
{
    // Check if we need to reserve more space
    if (stack_capacity == stack_size)
    {
        (stack_capacity == 0) ? reserve(1) : reserve(stack_capacity * 2);
    }
    stack_array_pointer[stack_size] = value;
    stack_size++;
}

/**
 * @brief pops an item off of the stack
 * 
 */
void mystack::pop()
{
    stack_size--;
}
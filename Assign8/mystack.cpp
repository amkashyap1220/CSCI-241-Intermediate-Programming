/**
 * @file mystack.cpp
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-18
 * 
 * Assignment 8
 * Course: CSCI 241
 * Section: 1
 */
#include <cstdlib>
#include "mystack.h"

/**
 * @brief Copy constuctor for mystack object
 * 
 * @param x 
 */
mystack::mystack(const mystack& x)
{
    stack_top_pointer = nullptr;
    stack_size = x.stack_size;

    clone(x);
}

/**
 * @brief Destroy the mystack::mystack object
 * 
 */
mystack::~mystack()
{
    clear();
}

/**
 * @brief overloaded assignment operator for mystack
 * 
 * @param x stack to be copied
 * @return mystack& reference to the current stack
 */
mystack& mystack::operator=(const mystack& x)
{
    if (this != &x)
    {
        clear();

        stack_size = x.stack_size;

        clone(x);
    }

    return *this;

}

/**
 * @brief gets the stack size
 * 
 * @return size_t the size
 */
size_t mystack::size() const
{
    return stack_size;
}

/**
 * @brief checks if the stack is empty
 * 
 * @return true if the stack is empty
 * @return false if otherwise
 */
bool mystack::empty() const
{
    return stack_size == 0;
}

/**
 * @brief pops the stack until its empty
 * 
 */
void mystack::clear()
{
    while(stack_size > 0)
    {
        pop();
    }

}

/**
 * @brief returns the top of the stack
 * 
 * @return const int& the int held at the top
 */
const int& mystack::top() const
{
    return stack_top_pointer->value;
}

/**
 * @brief removes an item from the top of the stack
 * 
 */
void mystack::pop()
{
    node* delete_node = stack_top_pointer;
    stack_top_pointer = stack_top_pointer->next;

    delete delete_node;

    stack_size--;
}

/**
 * @brief copies the linked list from the stack x to this object
 * 
 * @param x reference to a a constant stack to be cloned
 */
void mystack::clone(const mystack& x)
{
    node* last = nullptr;

    // for every node, go to the next node if not nullptr
    for (node* ptr = x.stack_top_pointer; ptr != nullptr; ptr = ptr->next)
    {
        // copy over nodes
        node* new_node = new node(ptr->value);

        if (last == nullptr)
        {
            stack_top_pointer = new_node;
        }
        else
        {
            last->next = new_node;
        }

        last = new_node;
    }
}

/**
 * @brief Inserts a new item at the top of the stack
 * 
 * @param value the value for the item in the stack
 */
void mystack::push(int value)
{
    node* new_node = new node(value, stack_top_pointer);

    stack_top_pointer = new_node;

    stack_size++;
}
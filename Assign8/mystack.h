/**
 * @file mystack.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * Due: 2021-03-18
 * 
 * Assignment 8
 * Course: CSCI 241
 * Section: 1
 */
#ifndef MYSTACK_H
#define MYSTACK_H

// Node
struct node
{
    int value;
    node *next;

    node(int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

class mystack
{
private:
    node *stack_top_pointer = nullptr;
    size_t stack_size = 0;
public:
    mystack() = default;
    mystack(const mystack& x);
    ~mystack();
    mystack& operator=(const mystack& x);
    size_t size() const;
    bool empty() const;
    void clear();
    const int& top() const;
    void push(int value);
    void pop();

    // Clone method, does work for = and the copy construct
    void clone(const mystack& x);
};

#endif
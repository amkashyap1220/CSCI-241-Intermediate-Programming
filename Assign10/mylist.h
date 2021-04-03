/************************************************************
 * @file mylist.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-02
 * Assignment 10
 ************************************************************/
#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

// Forward declaration of the mylist template class
template <class T>
class mylist;

// Forward declaration of the operator<< template function
template <class T>
std::ostream &operator<<(std::ostream &, const Queue<T> &);

template <class T>
struct node
{
    // Data memebers
    node<T> *next;
    node<T> *prev;
    T value;

    // Constructor
    node<T>(const T &value = T(), node<T> *next = nullptr, node<T> *prev = nullptr)
    {
        this->next = next;
        this->value = value;
        this->prev = prev;
    }
};

template <class T>
class mylist
{
    // friend declaration for the template function - note the special syntax
    friend std::ostream &operator<<<>(std::ostream &, const mylist<T> &);

private:
    // Data members
    size_t l_size = 0;
    node<T> *l_back = nullptr;
    node<T> *l_front = nullptr;

public:
    mylist() = default;
    ~mylist();
    mylist(const mylist<T> &x);
    mylist<T>& operator=<>(const mylist<T> &x);
    void clear();
    size_t size() const;
    bool empty() const;
    const T& front() const;
    T& front();
    const T& back() const;
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool operator==<>(const mylist<T> &rhs) const;
    bool operator<<>(const mylist<T> &rhs) const;

};

// Function definitions for the mylist class

template <class T>
mylist<T>::~mylist()
{
    clear();
}

template <class T>
mylist<T>::mylist(const mylist<T>& x)
{

}

template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{

}
template <class T>
void mylist<T>::push_back(const T &value)
{
    node<T> *new_node = new node<T>(value);

    //Step 1
    new_node->l_back;

    //step 2
    if (empty())
        l_front = new_node;
    else
        l_back->next = new_node;

    // step 3
    l_back = new_node;

    l_size++;
}

template <class T>
void mylist<T>::push_front(const T &value)
{
    node<T> *new_node = new node<T>(value);

    //Step 1
    new_node->l_front;

    //step 2
    if (empty())
        l_back = new_node;
    else
        l_front->prev = new_node;

    // step 3
    l_front = new_node;

    l_size++;
}

template <class T>
void mylist<T>::pop_back()
{
    if (empty())
        throw underflow_error("underflow in pop_back()");

    // Step 1
    node<T> *del_node = l_back;

    // Step 2
    l_back = del_node->prev;

    // Step 3
    if (l_back == nullptr)
        l_front = nullptr;
    else
        l_back->next = nullptr;

    // Step 4
    delete del_node;

    l_size--;
}

template <class T>
void mylist<T>::pop_front()
{
    if (empty())
        throw underflow_error("underflow in pop_back()");

    // Step 1
    node<T> *del_node = l_front;

    // Step 2
    l_front = del_node->next;

    // Step 3
    if (l_front == nullptr)
        l_back = nullptr;
    else
        l_front->prev = nullptr;

    // Step 4
    delete del_node;

    l_size--;
}
#endif

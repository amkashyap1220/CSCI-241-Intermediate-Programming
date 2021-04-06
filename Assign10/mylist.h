/************************************************************
 * @file mylist.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-08
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
std::ostream &operator<<(std::ostream &, const mylist<T> &);

/************************************************************
 * Node structure for mylist
 ************************************************************/
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

/************************************************************
 * mylist class
 ************************************************************/
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

    // private member functions
    void clone(const mylist<T> &x);

public:
    // Public member functions
    mylist() = default;
    ~mylist();
    mylist(const mylist<T> &x);
    mylist<T> &operator=(const mylist<T> &x);
    void clear();
    size_t size() const;
    bool empty() const;
    const T &front() const;
    T &front();
    const T &back() const;
    T &back();
    void push_front(const T &value);
    void push_back(const T &value);
    void pop_front();
    void pop_back();
    bool operator==(const mylist<T> &rhs) const;
    bool operator<(const mylist<T> &rhs) const;
};

// Function definitions for the mylist class

/************************************************************
 * destructor for mylist class
 ************************************************************/
template <class T>
mylist<T>::~mylist()
{
    clear();
}

/************************************************************
 * Copy constructor for mylist
 * @param x reference to mylist to be copied from
 ************************************************************/
template <class T>
mylist<T>::mylist(const mylist<T> &x)
{
    clear();
    clone(x);
}

/************************************************************
 * copies a mylist to another mylist
 * @param x mylist to clone from
 ************************************************************/
template <class T>
void mylist<T>::clone(const mylist<T> &x)
{
    // Loop through each node and push it on
    for (node<T> *ptr = x.l_front; ptr != nullptr; ptr = ptr->next)
    {
        push_back(ptr->value);
    }
}

/************************************************************
 * Clears a mylist object out
 ************************************************************/
template <class T>
void mylist<T>::clear()
{
    while (l_size != 0)
    {
        pop_back();
    }
}

/************************************************************
 * copy assignment operator
 * @param x list to copy from
 * @return mylist<T>& return pointer to this for cascading assignment
 ************************************************************/
template <class T>
mylist<T> &mylist<T>::operator=(const mylist<T> &x)
{
    if (this != &x)
    {
        clear();

        clone(x);
    }
    return *this;
}

/************************************************************
 * Returns the size of the mylist
 * @return size_t the size
 ************************************************************/
template <class T>
size_t mylist<T>::size() const
{
    return l_size;
}

/************************************************************
 * returns true is the list is empty
 * @return true if list empty
 * @return false if list is not
 ************************************************************/
template <class T>
bool mylist<T>::empty() const
{
    return (l_size == 0);
}

/************************************************************
 * returns the value of the front of the list
 * @return const T& value of the front
 ************************************************************/
template <class T>
const T &mylist<T>::front() const
{
    if (empty())
        throw underflow_error("underflow exception on call to front()");

    return l_front->value;
}

/************************************************************
 * return the value of the front of the list
 * @return T& value of the front
 ************************************************************/
template <class T>
T &mylist<T>::front()
{
    if (empty())
        throw underflow_error("underflow exception on call to front()");

    return l_front->value;
}

/************************************************************
 * return the value of the back of the list
 * @return T& value of the back
 ************************************************************/
template <class T>
const T &mylist<T>::back() const
{
    if (empty())
        throw underflow_error("underflow exception on call to back()");

    return l_back->value;
}

/************************************************************
 * return the value of the back of the list
 * @return T& value of the back
 ************************************************************/
template <class T>
T &mylist<T>::back()
{
    if (empty())
        throw underflow_error("underflow exception on call to back()");

    return l_back->value;
}

/************************************************************
 * pushes an item on to the back of the list
 * @param value value to be pushed on
 ************************************************************/
template <class T>
void mylist<T>::push_back(const T &value)
{
    node<T> *new_node = new node<T>(value);

    //Step 1
    new_node->prev = l_back;

    //step 2
    if (empty())
        l_front = new_node;
    else
        l_back->next = new_node;

    // step 3
    l_back = new_node;

    l_size++;
}

/************************************************************
 * pushes an item on to the front of the list
 * @param value value to be pushed on
 ************************************************************/
template <class T>
void mylist<T>::push_front(const T &value)
{
    node<T> *new_node = new node<T>(value);

    //Step 1
    new_node->next = l_front;

    //step 2
    if (empty())
        l_back = new_node;
    else
        l_front->prev = new_node;

    // step 3
    l_front = new_node;

    l_size++;
}

/************************************************************
 * pop an item from the back of the mylsit
 ************************************************************/
template <class T>
void mylist<T>::pop_back()
{
    if (empty())
        throw underflow_error("underflow exception on call to pop_back()");

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

/************************************************************
 * pop an item of the front of the list
 ************************************************************/
template <class T>
void mylist<T>::pop_front()
{
    if (empty())
        throw underflow_error("underflow exception on call to pop_front()");

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

/************************************************************
 * determines if two mylist are equal or not
 * @param rhs list to cross reference this with
 * @return true if the list are ==
 * @return false if the list are !=
 ************************************************************/
template <class T>
bool mylist<T>::operator==(const mylist<T> &rhs) const
{
    // First check the size
    if (rhs.l_size != l_size)
    {
        return false;
    }

    // if sizes are equal loop through and compare the values in each
    node<T> *ptr = l_front;
    node<T> *rptr = rhs.l_front;
    while (ptr != nullptr && rptr != nullptr)
    {
        // anything different return false 
        if (ptr->value != rptr->value)
        {
            return false;
        }
        ptr = ptr->next;
        rptr = rptr->next;
    }
    return true;
}

/************************************************************
 * determines if a mylist is less than another mylist
 * @param rhs list to cross reference this with
 * @return true if this list is less than the rhs list
 * @return false if this list is not less than the rhs list
 ************************************************************/
template <class T>
bool mylist<T>::operator<(const mylist<T> &rhs) const
{
    node<T> *rptr = rhs.l_front;
    node<T> *ptr = l_front; 

    // Loop through the list together 
    while (ptr != nullptr && rptr != nullptr)
    {
        if (ptr->value < rptr->value)
        {
            return true;
        }
        else if (ptr->value > rptr->value)
        {
            return false;
        }

        // move on to the next element (front to back)
        rptr = rptr->next;
        ptr = ptr->next;
    }

    return (l_size < rhs.l_size) ? true : false;
}

/************************************************************
 * stream insertion overload for the mylist objec 
 * @param os stream
 * @param obj the mylist object to put in the stream
 * @return std::ostream& returning back the stream object
 ************************************************************/
template <class T>
std::ostream &operator<<(std::ostream &os, const mylist<T> &obj)
{
    // Loop through the obj mylist passed and print each element followed by a space
    for (node<T> *ptr = obj.l_front; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->next == nullptr)
        {
            os << ptr->value;
            continue;
        }
        os << ptr->value << " ";
    }
    return os;
}
#endif

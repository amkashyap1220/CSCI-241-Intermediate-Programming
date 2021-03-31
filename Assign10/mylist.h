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
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
struct node
{
    // TODO
};

template <class T>
class mylist
{
    // friend declaration for the template function - note the special syntax
    friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);
        
    // TODO
};
        
// Function definitions for the mylist class

template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value);

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
void mylist<T>::push_front(const T& value)
{
    node<T>* new_node = new node<T>(value);

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
    node<T>* del_node = l_back;

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
    node<T>* del_node = l_front;

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

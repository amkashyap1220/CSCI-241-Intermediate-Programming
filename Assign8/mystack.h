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
template <class T>
struct node
{
    T value;
    node<T> *next;

    node<T>(const T &value = T(), node<T>* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

template <class T>
class mystack
{
private:
    node<T> *stack_top_pointer = nullptr;
    size_t stack_size = 0;
public:
    mystack() = default;
    mystack(const mystack<T> &x);
    ~mystack();
    mystack<T>& operator=(const mystack<T> &x);
    size_t size() const;
    bool empty() const;
    void clear();
    const T& top() const;
    void push(const T &value);
    void pop();

    // Clone method, does work for = and the copy construct
    void clone(const mystack& x);
};



/**
 * @brief Copy constuctor for mystack object
 * 
 * @param x 
 */
template <class T>
mystack<T>::mystack(const mystack<T> &x)
{
    stack_top_pointer = nullptr;
    stack_size = x.stack_size;

    clone(x);
}

/**
 * @brief Destroy the mystack::mystack object
 * 
 */
template <class T>
mystack<T>::~mystack()
{
    clear();
}

/**
 * @brief overloaded assignment operator for mystack
 * 
 * @param x stack to be copied
 * @return mystack& reference to the current stack
 */
template <class T>
mystack<T>& mystack<T>::operator=(const mystack<T> &x)
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
template <class T>
size_t mystack<T>::size() const
{
    return stack_size;
}

/**
 * @brief checks if the stack is empty
 * 
 * @return true if the stack is empty
 * @return false if otherwise
 */
template <class T>
bool mystack<T>::empty() const
{
    return stack_size == 0;
}

/**
 * @brief pops the stack until its empty
 * 
 */
template <class T>
void mystack<T>::clear()
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
template <class T>
const T& mystack<T>::top() const
{
    return stack_top_pointer->value;
}

/**
 * @brief removes an item from the top of the stack
 * 
 */
template <class T>
void mystack<T>::pop()
{
    node<T> *delete_node = stack_top_pointer;
    stack_top_pointer = stack_top_pointer->next;

    delete delete_node;

    stack_size--;
}

/**
 * @brief copies the linked list from the stack x to this object
 * 
 * @param x reference to a a constant stack to be cloned
 */
template <class T>
void mystack<T>::clone(const mystack<T> &x)
{
    node<T>* last = nullptr;

    // for every node, go to the next node if not nullptr
    for (node<T>* ptr = x.stack_top_pointer; ptr != nullptr; ptr = ptr->next)
    {
        // copy over nodes
        node<T>* new_node = new node<T>(ptr->value);

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
template <class T>
void mystack<T>::push(const T &value)
{
    node<T> *new_node = new node<T>(value, stack_top_pointer);

    stack_top_pointer = new_node;

    stack_size++;
}


#endif
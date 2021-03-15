// class mystack
// {
// private:
//     node *stack_top_pointer = nullptr;
//     size_t stack_size = 0;
// public:
//     mystack() = default;
//     mystack(const mystack& x);
//     ~mystack();
//     mystack& operator=(const mystack& x);
//     size_t size() const;
//     bool empty() const;
//     void clear();
//     const int& top() const;
//     void pop();

//     void clone(const mystack& x);
// };
#include <cstdlib>
#include "mystack.h"

mystack::mystack(const mystack& x)
{
    stack_top_pointer = nullptr;
    stack_size = x.stack_size;

    clone(x);
}

mystack::~mystack()
{
    clear();
}

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

size_t mystack::size() const
{
    return stack_size;
}

bool mystack::empty() const
{
    return stack_size == 0;
}

void mystack::clear()
{
    while(stack_size > 0)
    {
        pop();
    }

}

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

    for (node* ptr = x.stack_top_pointer; ptr != nullptr; ptr = ptr->next)
    {
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
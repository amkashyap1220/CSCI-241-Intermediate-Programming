/******************************************************************************************************
 * @file bstree.h
 * @author Alexander Kashyap (z1926618@students.niu.edu)
 * @version 0.1
 * @date 2021-04-13
 * 
 * Due: 2021-4-15
 * Assignment #11
 * 
 * @copyright Copyright (c) 2021
 * 
******************************************************************************************************/
#ifndef BSTREE
#define BSTREE

#include <cstdlib>
#include <algorithm>

template <class K, class V>
struct node
{
    K key;
    V value;
    node<K, V> *left;
    node<K, V> *right;

    node<K, V>(const K &k = K(), const V &v = V(), node<K, V> *l = nullptr, node<K, V> *r = nullptr)
    {
        key = k;
        value = v;
        left = l;
        right = r;
    }
};

template <class K, class V>
class bstree
{
private:
    node<K, V> *root;
    size_t tsize;

    void clone(node<K, V> *root);

public:
    bstree();
    ~bstree();
    bstree(const bstree<K, V> &x);
    size_t size() const;
    size_t height() const;
    size_t height(node<K, V> *n) const;
    bool empty() const;
    const node<K, V> *find(const K &key) const;
    const node<K, V> *find(const K &key, node<K, V> *root) const;
};

/******************************************************************************************************
 * Default contructor for the bstree template class
******************************************************************************************************/
template <class K, class V>
bstree<K, V>::bstree()
{
    // Initialize the data members
    root = nullptr;
    tsize = 0;
}

/******************************************************************************************************
 * Destructor for the bstree class
******************************************************************************************************/
template <class K, class V>
bstree<K, V>::~bstree()
{
    //clear();
}

/******************************************************************************************************
 * Copy contructor for bstree class
 * @param x reference to a const bstree to be copied
******************************************************************************************************/
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V> &x)
{
    preorder(x.root);
}

/******************************************************************************************************
 * Helper function for the copy constructor, recursive preorder traversal to copy a bstree
 * @param n a node in the bstree
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::clone(node<K, V> *root)
{
    if (root != nullptr)
    {
        insert(root->key, root->value);
        clone(root->left);
        clone(root->right);
    }
}

/******************************************************************************************************
 * Get the current size of the bstree
 * @return size_t the size of the bstree
******************************************************************************************************/
template <class K, class V>
size_t bstree<K, V>::size() const
{
    return tsize;
}

/******************************************************************************************************
 * Returns the height of the tree,
 * an empty tree has height 0.
 * @return size_t the height of the tree
******************************************************************************************************/
template <class K, class V>
size_t bstree<K, V>::height() const
{
    return height(root);
}

/******************************************************************************************************
 * Helper function for the height function, recursivly finds the height/depth of the tree
 * @param n a node in the tree
 * @return size_t the height of tree
******************************************************************************************************/
template <class K, class V>
size_t bstree<K, V>::height(node<K, V> *n) const
{
    if (n == nullptr)
    {
        return 0;
    }

    int leftheight = height(n->left);
    int rightheight = height(n->right);

    return std::max(leftheight, rightheight) + 1;
}

/******************************************************************************************************
 * Determines if the bstree is empty 
 * @return true if the bstree is empty
 * @return false if the bstree has at least one node
******************************************************************************************************/
template <class K, class V>
bool bstree<K, V>::empty() const
{
    return (tsize == 0);
}

/******************************************************************************************************
 * Attempts to find the specified key in the bstree
 * @param key key to be looking for
 * @return const node<K, V> bstree node if found, otherwise nullptr
******************************************************************************************************/
template <class K, class V>
const node<K, V> *bstree<K, V>::find(const K &key) const
{
    return find(key, root);
}

/******************************************************************************************************
 * Helper function for find, recursivly searches the bstree for the key 
 * @param key key to look for
 * @param root current node we are on
 * @return const node<K, V> bstree node if found, otherwise nullptr
******************************************************************************************************/
template <class K, class V>
const node<K, V> *bstree<K, V>::find(const K &key, node<K, V> *root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return find(key, root->left);
    }
    else
    {
        return find(key, root->right);
    }
}

#endif
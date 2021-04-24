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
#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************************************
 * Node struct
******************************************************************************************************/
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

/******************************************************************************************************
 * BST class
******************************************************************************************************/
template <class K, class V>
class bstree
{
private:
    // Data members
    node<K, V> *root;
    size_t tsize;

    // private methods
    node<K, V> *clone(node<K, V> *root);
    size_t height(node<K, V> *n) const;
    const node<K, V> *find(const K &key, node<K, V> *root) const;
    void preorder(node<K, V> *root) const;
    void postorder(node<K, V> *root) const;
    void inorder(node<K, V> *root) const;
    void print_level(node<K, V> *root, int level) const;
    const K &min(node<K, V> *root) const;
    const K &max(node<K, V> *root) const;

public:
    // public methods
    bstree();
    ~bstree();
    bstree(const bstree<K, V> &x);
    size_t size() const;
    size_t height() const;
    bool empty() const;
    const node<K, V> *find(const K &key) const;
    void preorder() const;
    void postorder() const;
    void inorder() const;
    void level_order() const;
    bool insert(const K &key, const V &value);
    const K &min() const;
    const K &max() const;
    void clear();
    void destroy(node<K, V> *root);
    bstree<K, V> &operator=(const bstree<K, V> &rhs);
    bool remove(const K& key);

    // EXAM 3
    size_t count_leaves(node<K, V>*) const;
    size_t count_leaves() const;
};

// EXAM 3
template <class K, class V>
size_t bstree<K, V>::count_leaves() const
{
    if (root == nullptr)
        return 0;
    else
        return count_leaves(root);
}

template <class K, class V>
size_t bstree<K, V>::count_leaves(node<K, V> *root) const
{
    // base case
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}


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
    clear();
}

/******************************************************************************************************
 * Reset the bst data members and call the function to destroy the branches
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::clear()
{
    destroy(root);
    root = nullptr;
    tsize = 0;
}

/******************************************************************************************************
 * Recursively destroys the dynamically allocated storage if the bst's nodes
 * @param root the current node
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::destroy(node<K, V> *root)
{
    if (root != nullptr)
    {
        destroy(root->left);
        destroy(root->right);

        delete[] root;
    }
}

/******************************************************************************************************
 * Overload assignment operator
 * @param rhs bst to be copied
 * @return bstree<K, V>& reference to this
******************************************************************************************************/
template <class K, class V>
bstree<K, V> &bstree<K, V>::operator=(const bstree<K, V> &rhs)
{
    if (this != &rhs)
    {
        clear();
        tsize = rhs.tsize;
        root = clone(rhs.root);
    }
    return *this;
}

/******************************************************************************************************
 * Remove a node
 * @param key key of node to be removed
 * @return true if node removed
 * @return false if node was not removed or not found
******************************************************************************************************/
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
    // root           : pointer to the root of the binary search tree
    // t_size         : tree size  
    // p              : pointer to the node to delete from the tree
    // parent         : pointer to the parent node of the node to delete from the tree (or 
    //                  nullptr if deleting the root node)
    // replace        : pointer to node that will replace the deleted node
    // replace_parent : pointer to parent of node that will replace the deleted node

    // Start at the root of the tree and search for the key to delete.
    node<K, V> *p = root;
    node<K, V> *parent = nullptr;
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // If the node to delte was not found, signal failure.
    if (p == nullptr)
    {
        return false;
    }

    node<K, V> *replace;
    node<K, V> *replace_parent;
    if (p->left == nullptr)
    {
        // Case 1a: p has no children. Replace p with its right child
        // (which is nullptr).
        //   - or -
        // Case 1b: p has no left child but has a right child. Replace 
        // p with its right child.
        replace = p->right;
    }
    else if (p->right == nullptr)
    {
        // Case 2: p has a left child but no right child. Replace p 
        // with its left child.
        replace = p->left;
    }
    else
    {
        // Case 3: p has two children. Replace p with its inorder predecessor.

        // Go left...
        replace_parent = p;
        replace = p->left;

        // ...then all the way to the right.
        while (replace->right != nullptr)
        {
            replace_parent = replace;
            replace = replace->right;
        }

        // If we were able to go to the right, make the replacement node's
        // left child the right child of its parent. Then make the left child
        // of p the replacement's left child.
        if (replace_parent != p)
        {
            replace_parent->right = replace->left;
            replace->left = p->left;
        }

        // Make the right child of p the replacement's right child.
        replace->right = p->right;
    }

    // Connect replacement node to the parent node of p (or the root if p has no parent).    
    if (parent == nullptr)
    {
        root = replace;
    }
    else
    {
        if (p->key < parent->key)
        {
            parent->left = replace;
        }
        else
        {
            parent->right = replace;
        }
    }

    // Delete the node, decrement the tree size, and signal success.
    delete[] p;
    tsize--;

    // Success
    return true;
}

/******************************************************************************************************
 * Copy contructor for bstree class
 * @param x reference to a const bstree to be copied
******************************************************************************************************/
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V> &x)
{
    tsize = x.tsize;
    root = clone(x.root);
}

/******************************************************************************************************
 * Helper function for the copy constructor, recursive preorder traversal to copy a bstree
 * @param n a node in the bstree
******************************************************************************************************/
template <class K, class V>
node<K, V> *bstree<K, V>::clone(node<K, V> *root)
{
    if (root != nullptr)
    {
        // Make a copy of the node pointed to by root
        node<K, V> *new_node = new node<K, V>(root->key, root->value);

        // Recursively copy the left and right subtrees of the node
        new_node->left = clone(root->left);
        new_node->right = clone(root->right);

        return new_node;
    }
    else
    {
        return nullptr;
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

/******************************************************************************************************
 * Inserts a new node into the bst
 * @param key key to be inserted
 * @param value value to be inserted
 * @return true if the node was successfully inserted
 * @return false if the node was not inserted
******************************************************************************************************/
template <class K, class V>
bool bstree<K, V>::insert(const K &key, const V &value)
{
    // root     : pointer to the root node of the tree (nullptr if tree is empty)
    // t_size   : tree size  
    // p        : pointer to a tree node
    // parent   : pointer to the parent node of p (nullptr if p points to the root node)
    // new_node : pointer used to create a new tree node

    // Start at the root of the tree
    node<K, V> *p = root;
    node<K, V> *parent = nullptr;

    // Search the tree for a null link or a duplicate key
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // If duplicates are disallowed, signal that insertion has failed
    if (p != nullptr)
    {
        return false;
    }

    // Otherwise, create a tree node and insert it as a new leaf node
    node<K, V> *new_node = new node<K, V>(key, value);

    if (parent == nullptr)
    {
        root = new_node;
    }
    else
    {
        if (new_node->key < parent->key)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }
    tsize++;

    // If duplicates are disallowed, signal that insertion has succeeded
    return true;
}

/******************************************************************************************************
 * Preorder traversal of the bstree
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::preorder() const
{
    preorder(root);
}

/******************************************************************************************************
 * Helper function for preorder, prints out key and value for the preorder traversal
 * @param root current node
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::preorder(node<K, V> *root) const
{
    if (root != nullptr)
    {
        cout << root->key << ": " << root->value << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

/******************************************************************************************************
 * Postorder traversal of the bstree
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::postorder() const
{
    postorder(root);
}

/******************************************************************************************************
 * Helper function for postorder, prints out key and value for the postorder traversal
 * @param root current node
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::postorder(node<K, V> *root) const
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << ": " << root->value << endl;
    }
}

/******************************************************************************************************
 * Preorder traversal of the bstree
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::inorder() const
{
    inorder(root);
}

/******************************************************************************************************
 * Helper function for preorder, prints out key and value for the preorder traversal
 * @param root current node
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::inorder(node<K, V> *root) const
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << ": " << root->value << endl;
        inorder(root->right);
    }
}

/******************************************************************************************************
 * Level order traversal of the bstree
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::level_order() const
{
    size_t h = height(root);

    for (int i = 1; i <= h; i++)
    {
        print_level(root, i);
    }
}

/******************************************************************************************************
 * Helper function for level order traversal, prints out key and value for the level order traversal
 * @param root current node
 * @param level current level on the bstree
******************************************************************************************************/
template <class K, class V>
void bstree<K, V>::print_level(node<K, V> *root, int level) const
{
    if (root == nullptr)
    {
        return;
    }

    if (level == 1)
    {
        cout << root->key << ": " << root->value << endl;
    }
    else if (level > 1)
    {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

/******************************************************************************************************
 * Helper function for min, recursively looks for the max key
 * @param root the current node
 * @return const K& the min key
******************************************************************************************************/
template <class K, class V>
const K &bstree<K, V>::min(node<K, V> *root) const
{
    if (root->left != nullptr)
    {
        return min(root->left);
    }
    return root->key;
}

/******************************************************************************************************
 * Find and returns the min key in the bstree
 * @return const K& the min key
******************************************************************************************************/
template <class K, class V>
const K &bstree<K, V>::min() const
{
    return min(root);
}

/******************************************************************************************************
 * Find and returns the max key in the bstree
 * @return const K& the max key
******************************************************************************************************/
template <class K, class V>
const K &bstree<K, V>::max() const
{
    return max(root);
}

/******************************************************************************************************
 * Helper function for max, recursively looks for the max key
 * @param root the current node
 * @return const K& the max key
******************************************************************************************************/
template <class K, class V>
const K &bstree<K, V>::max(node<K, V> *root) const
{
    if (root->right != nullptr)
    {
        return max(root->right);
    }
    return root->key;
}
#endif
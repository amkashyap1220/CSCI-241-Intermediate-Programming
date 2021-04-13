//***************************************************************
//
//  assign11.cpp
//  CSCI 241 Assignment 11
//
//  Created by name (z-ID).
//
//***************************************************************

#include <iostream>
#include <iomanip>
#include "bstree.h"

using std::cout;
using std::endl;

int main()
{
    cout << "*** Testing default constructor ***\n\n";
    
    bstree<int, double> t1;
    const node<int, double>* ptr;
    bool success;

    cout << std::fixed << std::setprecision(2);

    cout << "*** Testing size(), height(), empty(), and find() for empty tree ***\n\n";
    
    cout << "t1.size(): " << t1.size() << endl;
    cout << "t1.height(): " << t1.height() << endl;
    cout << "t1 is " << ((t1.empty()) ? "empty\n" : "not empty\n");
    ptr = t1.find(56);
    cout << "56 " << ((ptr) ? "found\n\n" : "not found\n\n");

    cout << "*** Testing traversals of empty tree ***\n\n";

    cout << "t1 preorder:\n\n";
    t1.preorder();
    cout << endl;

    cout << "t1 inorder:\n\n";
    t1.inorder();
    cout << endl;

    cout << "t1 postorder:\n\n";
    t1.postorder();
    cout << endl;

    cout << "t1 level order:\n\n";
    t1.level_order();
    cout << endl;

    cout << "*** Testing insertion of root node ***\n\n";

    t1.insert(56, 7.50);

    cout << "*** Testing size(), height(), empty(), min(), max(), and find() for tree with one node ***\n\n";
    
    cout << "t1.size(): " << t1.size() << endl;
    cout << "t1.height(): " << t1.height() << endl;
    cout << "t1 is " << ((t1.empty()) ? "empty\n" : "not empty\n");
    cout << "Minimum key: " << t1.min() << endl;
    cout << "Maximum key: " << t1.max() << endl << endl;
    ptr = t1.find(56);
    cout << "56 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl;
    else
        cout << "not found\n";
    ptr = t1.find(39);
    cout << "39 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl << endl;
    else
        cout << "not found\n\n";

    cout << "*** Testing traversals of tree with one node ***\n\n";

    cout << "t1 preorder:\n\n";
    t1.preorder();
    cout << endl;
    
    cout << "t1 inorder:\n\n";
    t1.inorder();
    cout << endl;
    
    cout << "t1 postorder:\n\n";
    t1.postorder();
    cout << endl;
    
    cout << "t1 level order:\n\n";
    t1.level_order();
    cout << endl;

    cout << "*** Testing insertion of additional nodes ***\n\n";

    t1.insert(34, 2.27);
    t1.insert(45, 3.91);
    t1.insert(68, 6.49);
    t1.insert(74, 7.03);
    t1.insert(21, 5.12);
    t1.insert(86, 9.74);
    t1.insert(62, 1.00);
    t1.insert(39, 8.99);

    cout << "*** Testing size(), height(), empty(), min(), max(), and find() ***\n\n";
    
    cout << "t1.size(): " << t1.size() << endl;
    cout << "t1.height(): " << t1.height() << endl;
    cout << "t1 is " << ((t1.empty()) ? "empty\n" : "not empty\n");
    cout << "Minimum key: " << t1.min() << endl;
    cout << "Maximum key: " << t1.max() << endl << endl;
    ptr = t1.find(56);
    cout << "56 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl;
    else
        cout << "not found\n";
    ptr = t1.find(39);
    cout << "39 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl;
    else
        cout << "not found\n";
    ptr = t1.find(65);
    cout << "65 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl << endl;
    else
        cout << "not found\n\n";

    cout << "*** Testing traversals of tree ***\n\n";

    cout << "t1 preorder:\n\n";
    t1.preorder();
    cout << endl;

    cout << "t1 inorder:\n\n";
    t1.inorder();
    cout << endl;

    cout << "t1 postorder:\n\n";
    t1.postorder();
    cout << endl;

    cout << "t2 level order:\n\n";
    t1.level_order();
    cout << endl;

    cout << "*** Testing insertion of duplicate key ***\n\n";
    
    success = t1.insert(39, 2.09);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t1.size(): " << t1.size() << endl << endl;

    bstree<int, double>& t2 = t1;

    cout << "*** Testing const correctness ***\n\n";
    
    cout << "t2.size(): " << t2.size() << endl;
    cout << "t2.height(): " << t2.height() << endl;
    cout << "t2 is " << ((t2.empty()) ? "empty\n" : "not empty\n");
    cout << "Minimum key: " << t2.min() << endl;
    cout << "Maximum key: " << t2.max() << endl << endl;
    ptr = t2.find(39);
    cout << "39 ";
    if (ptr)
        cout << "found, value: " << ptr->value << endl << endl;
    else
        cout << "not found\n\n";
    
    cout << "t2 preorder:\n\n";
    t2.preorder();
    cout << endl;
    
    cout << "t2 inorder:\n\n";
    t2.inorder();
    cout << endl;
    
    cout << "t2 postorder:\n\n";
    t2.postorder();
    cout << endl;
    
    cout << "t2 level order:\n\n";
    t2.level_order();
    cout << endl;

    cout << "*** Testing copy constructor ***\n\n";
    
    bstree<int, double> t3 = t1;
    bstree<int, double> t4 = t2;

    cout << "t3.size(): " << t2.size() << endl;
    cout << "t3.height(): " << t2.height() << endl << endl;

    cout << "t3 preorder:\n\n";
    t3.preorder();
    cout << endl;
    
    cout << "t3 inorder:\n\n";
    t3.inorder();
    cout << endl;

    cout << "*** Testing clear() ***\n\n";
    
    t3.clear();
    
    cout << "t3.size(): " << t3.size() << endl;
    cout << "t3.height(): " << t3.height() << endl << endl;

    cout << "*** Testing for shallow copy ***\n\n";

    cout << "t1.size(): " << t1.size() << endl;
    cout << "t1.height(): " << t1.height() << endl << endl;

    cout << "*** Testing copy assignment operator ***\n\n";

    bstree<int, double> t5;
    t5 = t1;

    cout << "t5.size(): " << t5.size() << endl;
    cout << "t5.height(): " << t5.height() << endl << endl;
    
    cout << "t5 preorder:\n\n";
    t5.preorder();
    cout << endl;
    
    cout << "t5 inorder:\n\n";
    t5.inorder();
    cout << endl;

    cout << "*** Testing assignment to self ***\n\n";

    t1 = t2;
    
    cout << "t1.size(): " << t1.size() << endl;
    cout << "t1.height(): " << t1.height() << endl << endl;

    cout << "*** Testing chained assignment ***\n\n";

    bstree<int, double> t6;
    
    t6.insert(8, 1.0);
    t6.insert(10, 2.0);
    t6.insert(27, 3.0);
    
    cout << "t6.size(): " << t6.size() << endl;
    cout << "t6.height(): " << t6.height() << endl << endl;
    
    cout << "t6 preorder:\n\n";
    t6.preorder();
    cout << endl;
    
    cout << "t6 inorder:\n\n";
    t6.inorder();
    cout << endl;

    t6 = t3 = t1;
    
    cout << "t6.size(): " << t6.size() << endl;
    cout << "t6.height(): " << t6.height() << endl << endl;
    
    cout << "t6 preorder:\n\n";
    t6.preorder();
    cout << endl;
    
    cout << "t6 inorder:\n\n";
    t6.inorder();
    cout << endl;

    cout << "*** Testing removal of non-existent node ***\n\n";
    
    success = t1.remove(66);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t1.size(): " << t1.size() << endl << endl;

    cout << "*** Testing removal of node with no children ***\n\n";

    success = t1.remove(21);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t1.size(): " << t1.size() << endl << endl;

    cout << "t1 preorder:\n\n";
    t1.preorder();
    cout << endl;
    
    cout << "t1 inorder:\n\n";
    t1.inorder();
    cout << endl;

    cout << "*** Testing removal of node with only right child ***\n\n";

    success = t3.remove(74);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t3.size(): " << t3.size() << endl << endl;

    cout << "t3 preorder: \n\n";
    t3.preorder();
    cout << endl;
    
    cout << "t3 inorder: \n\n";
    t3.inorder();
    cout << endl;

    cout << "*** Testing removal of node with only left child ***\n\n";
    
    success = t4.remove(45);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t4.size(): " << t4.size() << endl << endl;
    
    cout << "t4 preorder: \n\n";
    t4.preorder();
    cout << endl;
    
    cout << "t4 inorder: \n\n";
    t4.inorder();
    cout << endl;

    cout << "*** Testing removal of node with two children ***\n\n";
    
    success = t5.remove(68);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t5.size(): " << t5.size() << endl << endl;
    
    cout << "t5 preorder: \n\n";
    t5.preorder();
    cout << endl;
    
    cout << "t5 inorder: \n\n";
    t5.inorder();
    cout << endl;

    cout << "*** Testing removal of root node with two children ***\n\n";
    
    success = t6.remove(56);
    cout << ((success) ? "Success\n" : "Failure\n");
    cout << "t6.size(): " << t6.size() << endl << endl;
    
    cout << "t6 preorder: \n\n";
    t6.preorder();
    cout << endl;
    
    cout << "t6 inorder: \n\n";
    t6.inorder();
    cout << endl;

    return 0;
}

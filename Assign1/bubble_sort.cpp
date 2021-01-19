/**********************************************************
 * CSCI 241         Assignment 1      Spring 2021
 * @author Alexander Kashyap
 * @file bubble_sort.cpp
 * @version 1.0
 * Section: 1
 * Date Due: 1/21/2021
 * Purpose:  A program that sorts an array of ints using the bubble sort
 **********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void bubble_sort(int array[], int size);
void swap(int &a, int &b);

#define MAXARRAYSIZE 1000

int main(int argc, char * argv[]) {
    //defining the array
    int numbers[MAXARRAYSIZE];

    //filling the array with the values taken from the input strema
    int count = 0;
    while (cin >> numbers[count]) { 
        count++;
    }

    //calling the bubble sort
    bubble_sort(numbers, count);

    //print out the sorted numbers
    cout << right;
    int i = 0;
    for(; i < count; i++) {
        cout << setw(8) << numbers[i];
        if ((i + 1) % 8 == 0) {
            cout << endl;
        }
    }
    if (i % 8 != 0) {
        cout << endl;
    }

    return 0;
}

/**
 * sorts a passed array of length size using the insertion sort algorithem 
 * @param array array to be sorted
 * @param size size of the array to be sorted
 */
void bubble_sort(int array[], int size) {
    //iterate through and swap larger values to the end over each pass
    for (int maxElement = size - 1; maxElement > 0; maxElement--) {
        for (int index = 0; index < maxElement; index++) {
            if (array[index] > array[index+1]) {
                swap(array[index], array[index+1]);
            }
        }
    }
}

/**
 * swaps two integers in memory
 * @param a first int
 * @param b second int 
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
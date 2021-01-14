/***************************************************************
 CSCI 241         Program 10     Fall 2020
 @author Alexander Kashyap
 @file selection_sort.cpp
 @version 1.0
 Section: 
 Date Due: N/A
 Purpose:  the simplified version of the game Twenty-One
***************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void selection_sort(int array[], int size);
void swap(int &b, int &a);

//the max array size
#define MAXARRAYSIZE 1000

int main(int argc, char *argv[]) {
    //defining the array
    int numbers[MAXARRAYSIZE];

    //filling the array with the values taken from the input strema
    int count = 0;
    while (cin >> numbers[count]) {
        count++;
    }
    
    //call the sort funciton
    selection_sort(numbers, count);

    //print out the sorted numbers
    for(int i = 0; i < count; i++) {
        cout << setw(8) << numbers[i];
        if ((i + 1) % 8 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    
    return 0;
}

/**
 * sorts a passed array of length size using the selection sort algorithem 
 * @param array array to be sorted
 * @param size size of the array to be sorted
 */
void selection_sort(int array[], int size){
    int minIndex, minValue;
    //loop through each position in the array excluding the last
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        minValue = array[i];
        //for each position you must go then find the next smallest value left in the array
        for (int j = i + 1; j < size; j++) {
            if (array[j] < minValue) {
                minIndex = j;
                minValue = array[j];
            }
        }
        //after finding the smallest int left we swap them
        swap(array[minIndex],array[i]);
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

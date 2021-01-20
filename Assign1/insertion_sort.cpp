/**********************************************************
 * CSCI 241         Assignment 1      Spring 2021
 * @author Alexander Kashyap
 * @file insertion_sort.cpp
 * @version 1.0
 * Section: 1
 * Date Due: 1/21/2021
 * Purpose:  A program that sorts an array of ints using the inesertion sort
 **********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void insertion_sort(int array[], int size);

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
    insertion_sort(numbers, count);

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
void insertion_sort(int array[], int size){
    //loop through the array
    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int j = i;
        //compare the current element to each element before it
        while(j > 0 and array[j - 1] > temp) {
            array[j] = array[j-1];
            j--;
        }
        //once its at its position-place it.
        array[j] = temp;
    }
}

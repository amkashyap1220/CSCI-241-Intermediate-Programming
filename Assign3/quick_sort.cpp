/**********************************************************
 * CSCI 241         Assignment 3      Spring 2021
 * @author Alexander Kashyap
 * @file quick_sort.cc
 * @version 1.0
 * Section: 1
 * Date Due: 2/4/2021
 * Z-id: z1926618  
 **********************************************************/
#include <iostream>
#include <iomanip>
#include <utility>

// Define the max array size
#define MAXARRAYSIZE 1000

using namespace std;

// Funtion prototypes
void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

/**
 * The purpose of this program is to sort an array of integers read from
 * standard input using quick sort 
 * 
 * @param argc number of arguments passed
 * @param argv arugments
 */
int main(int argc, char* argv[]) {
    // defining the array
    int numbers[MAXARRAYSIZE];

    // filling the array with the values taken from the input strema
    int count = 0;
    while (cin >> numbers[count]) {
        count++;
    }
    
    // call the sort funciton
    quick_sort(numbers, 0, count - 1);

    // print out the sorted numbers
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
 * Defines a pivot point after a partition and recursivly calls itself
 * to sort
 * @param array int arrays to be sorted
 * @param start start index of array
 * @param end end index of array
 */
void quick_sort(int array[], int start, int end) {
    // Base case to return out
    if (start >= end) {
        return;
    }

    // Recursivly call quick_sort on each side of the pivot
    int pivot_point = partition(array, start, end);
    quick_sort(array, start, pivot_point - 1);
    quick_sort(array, pivot_point + 1, end);
}

/**
 * Places a pivot point in the correct spot in the array by moving smaller
 * values to the left of the pivot
 * @param array array/(section of array) of ints to be sorted
 * @param start start index of the array section
 * @param end  end index of the array section
 * @return index of pivot point
 */
int partition(int array[], int start, int end) {
    // Swap the mid point (pivot) with the start
    int mid = (start + end) / 2;
    swap(array[start], array[mid]);

    // Definine the pivot_value and pivot_index
    int pivot_index = start;
    int pivot_value = array[start];

    // Loop through the array and swap values less than the pivot_values
    for (int scan = start + 1; scan <= end; scan++) {
        if (array[scan] < pivot_value) {
            pivot_index++;
            swap(array[pivot_index], array[scan]);
        }
    }

    // Swap the pivot back to its correct position
    swap(array[start], array[pivot_index]);

    // Return the pivot_index
    return pivot_index;
}
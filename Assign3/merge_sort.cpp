/**********************************************************
 * CSCI 241         Assignment 3      Spring 2021
 * @author Alexander Kashyap
 * @file merge_sort.cc
 * @version 1.0
 * Section: 1
 * Date Due: 2/4/2021
 * Z-id: z1926618  
 **********************************************************/
#include <iostream>
#include <iomanip>

// Define the max array size
#define MAXARRAYSIZE 1000

using namespace std;

// Function Prototypes
void merge_sort(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);


/**
 * The purpose of this program is to sort an array of integers read from
 * standard input using merge sort 
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
    merge_sort(numbers, 0, count - 1);

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
 * Recursivly sorts a passed array using merge sort
 * @param array array to be sorted
 * @param start begining index of array
 * @param end ending index
 */
void merge_sort(int array[], int start, int end) {
    // Base case
    if (start >= end) {
        return;
    }

    // Define a midpoint to split the merge down
    int mid = (start + end - 1) / 2;

    // Recursivily call the merge with new midpoints down to 1 element
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    // Merge splits back together in correct order
    merge(array, start, mid, end);
    
}

/**
 * Merges two halfs
 * @param array array to be merged
 * @param start start index of array
 * @param mid mid point to split the array
 * @param end end index of array
 */
void merge(int array[], int start, int mid, int end) {
    // Define two temporary arrays to hold values from the array to be sorted
    int n1 = mid - start + 1; 
    int n2 = end - mid;
    int temp1[n1];
    int temp2[n2];

    // Initialize counteers that go through each of the 3 arrays
    int i = 0;
    int j = 0;
    int k = start;

    // Fill the temporary arrays
    for (int z = 0; z < n1; z++) {
        temp1[z] = array[start + z];
    }
    for (int z = 0; z < n2; z++) {
        temp2[z] = array[mid + 1 + z];
    }

    // Go back through the array filling from the temporary arrays, smaller values first
    while (i < n1 && j < n2) {
        if (temp1[i] <= temp2[j]) {
            array[k] = temp1[i];
            i++;
        } else {
            array[k] = temp2[j];
            j++;
        }
        k++;
    }

    // Fill with remaining elements
    while (i < n1) {
        array[k] = temp1[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = temp2[j];
        j++;
        k++;
    }
}
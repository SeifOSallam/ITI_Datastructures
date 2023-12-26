#include <iostream>
#include "mySearches.h"
using namespace std;

int binarySearch(int* arr, int size, int value) {
    int leftindex = 0;
    int rightindex = size-1;

    while (leftindex <= rightindex) {
        int midindex = (leftindex+rightindex)/2;
        if (value > arr[midindex]) {
            leftindex = midindex+1;
        }
        else if (value < arr[midindex]) {
            rightindex = midindex-1;
        }
        else {
            cout<<"Found at index "<<midindex<<endl;
            return midindex;
        }
    }
    cout<<"Not found.."<<endl;
    return -1;
}

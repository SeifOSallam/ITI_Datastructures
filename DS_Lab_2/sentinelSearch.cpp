#include <iostream>
#include "mySearches.h"
using namespace std;


int sentinelSearch(int* arr, int size, int value) {
    int last = arr[size - 1];
    arr[size - 1] = value;
    int i=0;
    while (arr[i] != value) {
        i++;
    }
    arr[size - 1] = last;
    if (i < (size - 1) || (arr[size - 1] == value))
        cout<<"Found value "<<value<<" at index "<<i<<endl;
    else
        cout<<"Element Not found"<<endl;
}

#include <bits/stdc++.h>
#include "mySorts.h"
#include "mySearches.h"
using namespace std;

void runMergesortDemo() {
    cout<<"RUNNING MERGE SORT..."<<endl;
    int arr[]={15, 7, 3, 10, 19, 14};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    cout<<"Sorted using merge\n";
    for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";
    }
    cout<<endl<<endl<<endl;
}

void runQuicksortDemo() {
    cout<<"RUNNING QUICKSORT..."<<endl;
    int arr[]={10, 50, 20, 15, 17, 30, 40};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout<<"Sorted using quicksort\n";
    for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";
    }
    cout<<endl<<endl<<endl;
}

void runBinarySearch() {
    cout<<"RUNNING BINARY SEARCH..."<<endl;
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res = binarySearch(arr, n, 10);
    cout<<endl<<endl<<endl;
}

void runSentinelSearch() {
    cout<<"RUNNING SENTINEL SEARCH..."<<endl;
    int arr[]={5, 8, 1, 4, 10, 50, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res = sentinelSearch(arr, n, 10);
    cout<<endl<<endl<<endl;
}

void runLinearSearch() {
    Employee* emps = new Employee[5];
    emps[0] = Employee(1, "ahmed", 3.4);
    emps[1] = Employee(2, "emad", 5.1);
    emps[2] = Employee(3, "hamed", 100);
    emps[3] = Employee(4, "john", 50);
    emps[4] = Employee(5, "stefen", 30);
    searchAlgo<int>* linearid = new linearByID<int>();
    searchAlgo<string>* linearname = new linearByName<string>();
    searchAlgo<float>* linearsal = new linearBySalary<float>();
    linearid->searchElement(emps, 5, 1);
    linearname->searchElement(emps, 5, "john");
    linearsal->searchElement(emps, 5, 30);

}

int main() {
    runQuicksortDemo();
    runMergesortDemo();
    runBinarySearch();
    runSentinelSearch();
    runLinearSearch();
    return 0;
}

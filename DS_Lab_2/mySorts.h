#ifndef MYSORTS_H_INCLUDED
#define MYSORTS_H_INCLUDED

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int bg, int end);

int partitionArr(int arr[],int low,int high);
void quickSort(int arr[],int low,int high);

#endif // MYSORTS_H_INCLUDED

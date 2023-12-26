#include <iostream>
#include "mySorts.h"
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];


    int m = 0, n = 0;


    int indexOfMergedArray = left;

    while (m < subArrayOne && n < subArrayTwo)
    {
        if (leftArray[m] <=
            rightArray[n])
        {
            arr[indexOfMergedArray] = leftArray[m];
            m++;
        }
        else
        {
            arr[indexOfMergedArray] =
            rightArray[n];
            n++;
        }
        indexOfMergedArray++;
    }


    while (m < subArrayOne)
    {
        arr[indexOfMergedArray] =
        leftArray[m];
        m++;
        indexOfMergedArray++;
    }

    while (n < subArrayTwo)
    {
        arr[indexOfMergedArray] =
        rightArray[n];
        n++;
        indexOfMergedArray++;
    }
}

void mergeSort(int arr[], int bg, int end)
{
    if (bg >= end)
        return;

    int mid = bg + (end - bg) / 2;
    mergeSort(arr, bg, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, bg, mid, end);
}

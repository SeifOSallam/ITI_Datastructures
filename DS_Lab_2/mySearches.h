#ifndef MYSEARCHES_H_INCLUDED
#define MYSEARCHES_H_INCLUDED
#include "Employee.h"
template <class T>
class searchAlgo {
public:
    virtual void searchElement(Employee* e, int size, T element)=0;
};

template <class T>
class linearByID : public searchAlgo<T> {
public:
    void searchElement(Employee* e, int size, T element);
};

template <class T>
class linearByName : public searchAlgo<T> {
public:
    void searchElement(Employee* e, int size, T element);
};

template <class T>
class linearBySalary : public searchAlgo<T> {
public:
    void searchElement(Employee* e, int size, T element);
};

int binarySearch(int* arr, int size, int value);
int sentinelSearch(int* arr, int size, int value);




template <class T>
void linearByID<T>::searchElement(Employee* e,int size, T element) {
    for(int i=0;i<size;i++) {
        if (e[i].id == element) {
            cout<<"Found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Not found..."<<endl;
}

template <class T>
void linearByName<T>::searchElement(Employee* e, int size, T element) {
    for(int i=0;i<size;i++) {
        if (e[i].name == element) {
            cout<<"Found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Not found..."<<endl;
}

template <class T>
void linearBySalary<T>::searchElement(Employee* e, int size, T element) {
    for(int i=0;i<size;i++) {
        if (e[i].salary == element) {
            cout<<"Found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Not found..."<<endl;
}






#endif // MYSEARCHES_H_INCLUDED

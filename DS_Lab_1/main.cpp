#include <iostream>

using namespace std;

class Employee {
public:
    int id;
    string name;
    string email;
    Employee(){}
    Employee(int id, string name, string email) {
        this->id = id;
        this->name = name;
        this->email = email;
    }
    void printData() {
        cout<<"ID: "<<id<<"\t"<<"NAME: "<<name<<"\t"<<"EMAIL: "<<email<<endl;
    }
};

class sortingClass {
public:
    virtual void sortEmployees(Employee* e,int siz)=0;
};

class bubbleAsc: public sortingClass {
public:
    void sortEmployees(Employee* e,int siz) {
        for (int i=0;i<siz-1;i++) {
            for (int j=0;j<siz-1-i;j++) {
                if (e[j].id > e[j+1].id) {
                    swap(e[j], e[j+1]);
                }
            }
        }
    }
};

class bubbleDesc: public sortingClass {
public:
    void sortEmployees(Employee* e,int siz) {
        for (int i=0;i<siz-1;i++) {
            for (int j=0;j<siz-1-i;j++) {
                if (e[j].id < e[j+1].id) {
                    swap(e[j], e[j+1]);
                }
            }
        }
    }
};


void selectionSort(int* arr, int siz) {
    for (int i=0;i<siz-1;i++) {
        int minIndex = i;
        for (int j=i+1;j<siz;j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void selectionSort(string* arr, int siz) {
    for (int i=0;i<siz-1;i++) {
        int minIndex = i;
        for (int j=i+1;j<siz;j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


int main()
{
    int* arr = new int[5]{5,1,9,10,4};
    string* names = new string[5]{"ahmed","emad","alaa","Hosny","Asmaa"};
    selectionSort(arr, 5);
    selectionSort(names, 5);
    Employee emp1(8,"ahmed","ahmed@ahmed");
    Employee emp2(2,"ahmed","ahmed@ahmed");
    Employee emp3(10,"ahmed","ahmed@ahmed");
    Employee emp4(4,"ahmed","ahmed@ahmed");
    Employee emp5(20,"ahmed","ahmed@ahmed");
    Employee* employees = new Employee[5];
    Employee* employees2 = new Employee[5];
    employees[0] = emp1;
    employees[1] = emp2;
    employees[2] = emp3;
    employees[3] = emp4;
    employees[4] = emp5;
    employees2[0] = emp1;
    employees2[1] = emp2;
    employees2[2] = emp3;
    employees2[3] = emp4;
    employees2[4] = emp5;
    sortingClass* mysortasc = new bubbleAsc();
    sortingClass* mysortdesc = new bubbleDesc();
    mysortasc->sortEmployees(employees, 5);
    mysortdesc->sortEmployees(employees2, 5);
    for (int i=0;i<5;i++) {
        cout<<arr[i]<<endl;
    }
    cout<<"-----------------------"<<endl;
    for (int i=0;i<5;i++) {
        cout<<names[i]<<endl;
    }
    cout<<"-----------------------"<<endl;
    for (int i=0;i<5;i++) {
        employees[i].printData();
    }
    cout<<"-----------------------"<<endl;
    for (int i=0;i<5;i++) {
        employees2[i].printData();
    }
}

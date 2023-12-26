#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

using namespace std;
class Employee {
public:

    int id;
    string name;
    float salary;
    Employee(){}
    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
};

#endif // EMPLOYEE_H_INCLUDED

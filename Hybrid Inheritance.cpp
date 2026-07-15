#include <iostream>
using namespace std;

class Person {
public:
    void info() {
        cout << "This is a person" << endl;
    }
};

class Student : public Person {
public:
    void study() {
        cout << "Student is studying" << endl;
    }
};

class Employee {
public:
    void work() {
        cout << "Employee is working" << endl;
    }
};

class Intern : public Student, public Employee {
public:
    void training() {
        cout << "Intern is doing training" << endl;
    }
};

int main() {
    Intern i;

    i.info();
    i.study();
    i.work();
    i.training();

    return 0;
}
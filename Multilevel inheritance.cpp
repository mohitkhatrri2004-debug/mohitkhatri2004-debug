#include <iostream>
using namespace std;

class Grandfather {
public:
    void house() {
        cout << "Grandfather has a house" << endl;
    }
};

class Father : public Grandfather {
public:
    void car() {
        cout << "Father has a car" << endl;
    }
};

class Child : public Father {
public:
    void bike() {
        cout << "Child has a bike" << endl;
    }
};

int main() {
    Child c;

    c.house();
    c.car();
    c.bike();

    return 0;
}
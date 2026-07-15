#include<bits/stdc++.h>
using namespace std;
class Animal{
public:
    virtual void show(){
        cout << "Animal is a Animal" << endl;
    }
};
class dog : public Animal{
public:
    void show() override{
        cout << "Dog barks" << endl;
    }
};
class cat : public Animal{
public:
    void show() override{
        cout << "Cat meow" << endl;
    }
};
int main(){
    Animal *a;
    dog d;
    cat c;

    a = &d;
    a -> show();

    a = &c;
    a -> show();
    return 0;
}
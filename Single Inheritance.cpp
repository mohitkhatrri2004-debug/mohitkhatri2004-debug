#include<bits/stdc++.h>
using namespace std;
class Dog{
public:
    void show(){
        cout << "Dog barks" << endl;
    }
};
class Cat : public Dog{
public:
    void show1(){
        cout << "Cat says MEOW";
    }
};
int main(){
    Cat c;
    c.show();
    c.show1();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Car{
public:
    void show(){
        cout << "Car starts" << endl;
    }
};
class Bike{
public:
     void show1(){
        cout << "Bike starts" << endl;
     }
};
class Vehicle : public Car,public Bike{
public:
     void show2(){
        cout << "They both go fast" << endl;
     }
};
int main(){
      Vehicle v;
      v.show();
      v.show1();
      v.show2();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Function{
public:
    int add(int a,int b){
        return a + b;
    }
    double add(double a,double b){
        return a + b;
    }
    int add(int a,int b,int c){
        return a + b + c;
    }
};
int main(){
    Function f;
    cout << "Addition 1 : " << f.add(1,2) << endl;
    cout << "Addition 2 : " << f.add(1.5,2.5) << endl;
    cout << "Addition 3 : " << f.add(1,2,3) << endl;
    return 0;
}
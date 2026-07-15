#include<bits/stdc++.h>
using namespace std;
class Number{
private:
    int value;
public:
    Number(int v){
        value = v;
    }
    Number operator + (Number n){
        Number result(value + n.value);
        return result;
    }
    void display(){
        cout << value << endl;
    }
};
int main(){
    Number n1(5);
    Number n2(10);

    Number n3 = n1 + n2;

    n3.display();
    return 0;
}
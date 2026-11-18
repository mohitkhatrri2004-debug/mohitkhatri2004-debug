#include<bits/stdc++.h>
using namespace std;

int main(){
    int poly[] = {1,2,3,4,5};
    int n = 5;
    int x = 2;
    int result = 0;
    for(int i=0;i<n;i++){
        int power = 1;
        for(int j=0;j<i;j++){
            power = power*x;
        }

        result += poly[i] * power;
    }
    cout << result;
    return 0;
}
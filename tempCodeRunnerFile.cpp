#include<bits/stdc++.h>
using namespace std;
int foundIndex = -1;
void findValue(int arr[],int value,int &n){
    for(int i=0;i<n;i++){
        if(arr[i] == value){
            cout << "Element found at : " << i << endl;
            foundIndex = i;
            break;
        }
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int value = 4;
    int n = 6;
    findValue(arr,value,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
}
int main(){
    int arr[] = {51,22,3,124,55};
    int n = 5;
    reverse(arr,5);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
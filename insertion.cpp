#include<bits/stdc++.h>
using namespace std;
void insertion(int arr[],int idx,int value, int &n){
    for(int i=n;i>idx;i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = value;
    n++;
}
void deletion(int arr[],int idx,int &n){
    for(int i=idx;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    n--;
}
int main(){
    int arr[] = {15,13,14,12,11};
    int n = 5;
    int idx = 4;
    int idx1 = 3;
    int value = 45;
    insertion(arr,idx,value,n);
    deletion(arr,idx1,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
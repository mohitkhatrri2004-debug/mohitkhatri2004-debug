#include<bits/stdc++.h>
using namespace std;
int insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
int main(){
    int arr[] = {15,13,12,11,14};
    int n = 5;
    insertionsort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
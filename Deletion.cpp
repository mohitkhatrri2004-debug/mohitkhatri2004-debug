#include<bits/stdc++.h>
using namespace std;
void deletion(int arr[],int idx,int &n){
    for(int i=idx;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    n--;
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int idx = 3;
    deletion(arr,idx,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
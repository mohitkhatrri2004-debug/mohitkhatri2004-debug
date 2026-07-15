#include<bits/stdc++.h>
using namespace std;
void traverse(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    traverse(arr,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void bubblesort(int arr[] , int n){
    bool flag = false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(!flag){
        return;
    }
    }
}
int main(){
    int arr[] = {14,10,12,9,5};
    int n = 5;
    bubblesort(arr , n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
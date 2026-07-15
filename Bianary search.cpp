#include<bits/stdc++.h>
using namespace std;
int bianarysearch(int arr[],int key,int low,int high,int &n){
    for(int i=0;i<n;i++){
        int mid = (low + high)/2;
        if(arr[i] == key){
            cout << "Element found at : " << i << endl;
            return 0;
        }else if(arr[i] < key){
            mid = low + 1;
        }else{
            mid = high - 1;
        }
    }
    cout << "Element not found" << endl;
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    int low = 0;
    int high = n-1;
    int key = 4;
    bianarysearch(arr,key,low,high,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int st,int end){
    int idx = st-1, pivot = arr[end];
    for(int i=st;i<end;i++){
        if(arr[i] <= pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}
void quickSort(int arr[],int st,int end){
    if(st < end){
    int pivIdx = partition(arr,st,end);
    quickSort(arr,st,pivIdx-1);
    quickSort(arr,pivIdx+1,end);
    }
} 
int main(){
    int arr[] = {5,2,3,1,8};
    int n = 5;
    int st = 0, end = n-1;
    // partition(arr,st,end);
    quickSort(arr,st,end);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
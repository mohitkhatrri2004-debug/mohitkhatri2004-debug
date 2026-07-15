#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int st, int end){
    int idx = st-1 , pivot = arr[end];
    for(int i=st;i<end;i++){
        if(arr[i] <= pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quicksort(int arr[] , int st, int end){
    if(st < end){
        int pivotIdx = partition(arr,st,end);
        quicksort(arr,st,pivotIdx-1);
        quicksort(arr,pivotIdx+1,end);
    }
}
int main(){
    int arr[] = {3,5,2,4,1};
    int n = 5;
    int st = 0;
    int end = n-1;

    partition(arr,st,end);
    quicksort(arr,st,end);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int st, int mid, int end);

void mergeSort(int arr[],int st,int end){
    if(st < end){
    int mid = st + ((end - st) / 2);

    mergeSort(arr,st,mid); 
    mergeSort(arr,mid+1,end);

    merge(arr, st, mid, end);
    }
}

void merge(int arr[],int st,int mid,int end){
    vector<int>temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
            i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
            j++;
    }

    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
}
int main(){
    int arr[] = {5,1,4,9,0};
    int n = 5;
    int st = 0;
    int end = n-1;

    mergeSort(arr,st,end);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
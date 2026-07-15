#include<bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[], int &n){
    for(int i=0;i<n-1;i++){
        int SI = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[SI]){
                SI = j;
            }
        }
        swap(arr[SI],arr[i]);
    }
}
int main(){
    int arr[] = {15,13,11,14,12};
    int n = 5;
    SelectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
} 
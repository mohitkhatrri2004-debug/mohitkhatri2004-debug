#include<bits/stdc++.h>
using namespace std;
int getMax(int arr[],int n){
    int max = arr[0];

    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[],int n,int place){
    int output[n];
    int count[10] = {0};

    for(int i=0;i<n;i++){
        int digit = (arr[i]/place)%10;
        count[digit]++;
    }

    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        int digit = (arr[i]/place)%10;

        output[count[digit]-1] = arr[i];
        count[digit]--;
    }
    
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}
void radixSort(int arr[],int n){
    int max2 = getMax(arr,n);

    for(int place=1; max2/place > 0;place*=10){
        countingSort(arr,n,place);
    }
}

int main(){
    int arr[] = {1,4,2,3,5};
    int n = 5;
    radixSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int arr[20][20];

    cout << "Enter matrix elements:\n";

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;

    // Count non-zero elements
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] != 0) {
                count++;
            }
        }
    }

    int sparse[100][3];

    // First row stores matrix information
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = count;

    int k = 1;

    // Store non-zero elements
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse Matrix (3-Tuple):\n";

    for(int i=0; i<=count; i++) {
        for(int j=0; j<3; j++) {
            cout << sparse[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


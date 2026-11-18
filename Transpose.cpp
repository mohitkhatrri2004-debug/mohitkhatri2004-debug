
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

    int trans[20][20];

    // Transpose logic
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            trans[j][i] = arr[i][j];
        }
    }

    cout << "\nTranspose of matrix:\n";

    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

void tampil(int arr[3][3]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int i, int j) {
    int temp = a[i][j];
    a[i][j] = b[i][j];
    b[i][j] = temp;
}

void tukarPointer(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};

    int x = 10, y = 20;
    int *px = &x, *py = &y;

    cout << "Array A:\n"; tampil(A);
    cout << "\nArray B:\n"; tampil(B);

    tukarArray(A, B, 0, 0);

    cout << "\nSetelah ditukar:\n";
    cout << "Array A:\n"; tampil(A);
    cout << "\nArray B:\n"; tampil(B);

    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(px, py);
    cout << "Setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
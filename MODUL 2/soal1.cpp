#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int pilihan;

    cout << "=== Program Operasi Matriks 3x3 ===\n";

    // Input matriks A
    cout << "\nMasukkan elemen matriks A:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    // Input matriks B
    cout << "\nMasukkan elemen matriks B:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }

    // Pilihan operasi
    cout << "\nPilih operasi:\n";
    cout << "1. Penjumlahan\n";
    cout << "2. Pengurangan\n";
    cout << "3. Perkalian\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    // Proses operasi sesuai pilihan
    if (pilihan == 1) {
        cout << "\nHasil Penjumlahan (A + B):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = A[i][j] + B[i][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else if (pilihan == 2) {
        cout << "\nHasil Pengurangan (A - B):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = A[i][j] - B[i][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else if (pilihan == 3) {
        cout << "\nHasil Perkalian (A x B):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    C[i][j] += A[i][k] * B[k][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else {
        cout << "\nPilihan tidak valid.\n";
    }

    return 0;
}
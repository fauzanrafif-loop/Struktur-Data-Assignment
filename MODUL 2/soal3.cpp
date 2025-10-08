#include <iostream>

using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] < min) min = arr[i];
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > max) max = arr[i];
    return max;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for(int i=0; i<n; i++)
        total += arr[i];
    cout << "Nilai rata-rata: " << total / n << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10, menu;

    cout << "--- Menu Program Array ---\n";
    cout << "1. Tampilkan isi array\n";
    cout << "2. Cari nilai maksimum\n";
    cout << "3. Cari nilai minimum\n";
    cout << "4. Hitung nilai rata-rata\n";
    cout << "Pilih salah satu menu diatas: ";
    cin >> menu;

    switch(menu) {
        case 1:
            cout << "Masukkan isi array: ";
            for(int i=0; i<n; i++) cout << arrA[i] << " ";
            cout << endl;
            break;
        case 2:
            cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
            break;
        case 3:
            cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
            break;
        case 4:
            hitungRataRata(arrA, n);
            break;
    }
}
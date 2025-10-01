#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan Angka : ";
    cin >> a;
    cout << "Masukkan Angka Selanjutnya: ";
    cin >> b;

    cout << "Hasil Penjumlahan : " << a + b << endl;
    cout << "Hasil Pengurangan : " << a - b << endl;
    cout << "Hasil Perkalian : " << a * b << endl;
    cout << "Hasil Pembagian : " << a / b << endl;
    return 0;
}
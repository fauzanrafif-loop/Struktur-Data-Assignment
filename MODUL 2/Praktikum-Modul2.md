# <h1 align="center">Laporan Praktikum Modul 2 Pengenalan Bahasa C++ (Bagian Kedua) </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

Bahasa pemrogramanan merupakan instruksi standar untuk memerintahkan sebuah komputer. Bahasa pemrograman dapat dimanfaatkan untuk membagun sebuah sistem aplikasi sesuai dengan kebutuhan yang dapat dimanfaatkan dalam berbagai bidang. Salah satu di antaranya adalah bahasa pemrograman C++ di mana bahasa pemrograman C++ ini merupakan hybrid dari bahasa C. 

## Guided 

### 1. Array

```C++
#include <iostream>

using namespace std;

int main(){
    int arr1D[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" <<  endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
    }
    cout << endl;

    // Array Multi Dimensi (2D)
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Array Multi Dimensi (3D)
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };
    cout << "Array 3 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
.....

### 2. Prosedur

```C++
#include <iostream>

using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}

int main(){
    int jum;
    cout << "Jumlah Baris Kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
..........

### 3. Pointer
```C++
#include <iostream>

using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main (){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of a : " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl;

    return 0;
}
```
..........

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
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
```
#### Output:
<img width="1648" height="256" alt="Image" src="https://github.com/user-attachments/assets/5a705dd0-8bc2-46af-a58b-735c789a6e38" />

Kode di atas digunakan untuk mengubah angka menjadi tulisan.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
#include <iostream>

using namespace std;

int main() {
    string dasar[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    
    if (angka == 0) cout << dasar[0];
    else if (angka == 10) cout << "sepuluh";
    else if (angka == 11) cout << "sebelas"; 
    else if (angka < 10) cout << dasar[angka];
    else if (angka < 20) cout << dasar[angka-10] << " belas";
    else if (angka == 100) cout << "seratus";
    else if (angka < 100) {
        cout << dasar[angka/10] << " puluh";
        if (angka % 10 > 0) cout << " " << dasar[angka % 10];
    }
    else cout << "Tidak ada";
    
    cout << endl;
    return 0;
}
```
#### Output:
<img width="1308" height="113" alt="Image" src="https://github.com/user-attachments/assets/46146db9-ae96-4968-837d-f540f9e8125a" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : 
### arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : 
--- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata
```C++
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int baris = 0; baris <= n; baris++) {
        for (int i = 0; i < baris * 2; i++) {
            cout << " ";
        }
        
        for (int i = n - baris; i > 0; i--) {
            cout << i << " ";
        }
        
        cout << "* ";
        
        for (int i = 1; i <= n - baris; i++) {
            cout << i << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
```
#### Output:
<img width="1682" height="167" alt="Image" src="https://github.com/user-attachments/assets/63747614-8ee9-4130-ac96-40f6b3e9912f" />
Kode di atas digunakan untuk membuat pola angka yang dimana jika kita masukan angka berapapun akan membentuk pola yang berurutan seperti segitiga terbalik.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

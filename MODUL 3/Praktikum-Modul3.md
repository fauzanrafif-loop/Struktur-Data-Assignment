# <h1 align="center">Laporan Praktikum Modul 3 Tentang Abstract Data Type (ADT) </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

...............

## Guided 

### 1. Operator Aritmatika dan Operator Logika

```C++
#include <iostream>
using namespace std;

int main () {
    int a;
    int b;
    
    cout << "Masukan angka1: ";
    cin >> a;
    cout << "Masukan angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //Operator logika
    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
    return 0;
}
```
......................

### 2. Percabangan

```C++
#include <iostream>
using namespace std;

int main () {
    int angka1 = 10;
    int angka2 = 20;

    if (angka1 > angka2) {
        cout << "angka-1 lebih besar dari angka-2" << endl;
    } else if (angka1 < angka2) {
        cout << "angka-1 lebih kecil dari angka-2" << endl;
    } else {
        cout << "angka-1 sama dengan angka-2" << endl;
    }

    return 0;
}
```
....................

### 3. Struct

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    int jumlah;
    cout << "Masukan jumlah mahasiswa: ";
    cin >> jumlah;
    Mahasiswa mhs[jumlah];
    
    // input data menggunakan loop
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "Umur: ";
        cin >> mhs[i].umur;
    }

    // tampilkan data
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1
             << " | Nama: " << mhs[i].nama
             << " | Umur: " << mhs[i].umur << endl;
    }

    return 0;
}
```
................

## Unguided 

### 1. Buatkan program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

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

................

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.  

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

..............

### 3. Buatlah program yang dapat menerima input dan output sebagai berikut:
<img width="269" height="261" alt="Image" src="https://github.com/user-attachments/assets/86cd0bc5-9848-4d7d-beb0-962e352e700c" />

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
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/dc49786a-daaa-4f1e-90f5-bebb2f1fd9b2" />

## Kesimpulan
...........
## Referensi
[1] ..........

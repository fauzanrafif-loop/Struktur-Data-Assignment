# <h1 align="center">Laporan Praktikum Modul 1 Tentang Pengenalan Bahasa C++ </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

Bahasa pemrogramanan merupakan instruksi standar untuk memerintahkan sebuah komputer. Bahasa pemrograman dapat dimanfaatkan untuk membagun sebuah sistem aplikasi sesuai dengan kebutuhan yang dapat dimanfaatkan dalam berbagai bidang. Salah satu di antaranya adalah bahasa pemrograman C++ di mana bahasa pemrograman C++ ini merupakan hybrid dari bahasa C. 

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
Kode di atas digunakan untuk melakukan perhitungan bilangan mulai dari penjumlahan, pengurangan, perkalian, maupun pembagian. serta operator logika yang digunakan untuk menggabungkan atau membandingkan ekspresi logika.

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
Kode di atas digunakan untuk membandingkan angka1 yang bernilai 10 dan angka2 yang bernilai 20. jika angka1 yang lebih besar dari angka2 maka outputnya akan menampilkan bahwa angka1 lebih besar dari angka2, begitu juga sebaliknya dan jika angka keduanya sama maka akan menghasilkan angka1 lebih kecil dari angka2.

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
kode diatas merupakan sebuah struct bernama Mahasiswa yang memiliki dua atribut, yaitu nama bertipe string dan umur bertipe integer yang digunakan untuk mencatat dan menampilkan data mahasiswa berdasarkan input pengguna.

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

Kode di atas digunakan untuk melakukan perhitungan bilangan mulai dari penjumlahan, pengurangan, perkalian, maupun pembagian.

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
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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
Kode di atas digunakan untuk membuat pola angka yang dimana jika kita masukan angka berapapun akan membentuk pola yang berurutan 

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

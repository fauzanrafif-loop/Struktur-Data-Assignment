# <h1 align="center">Laporan Praktikum Modul 3 Tentang Abstract Data Type (ADT) </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

Abstract Data Type (ADT) atau Tipe Data Abstrak adalah konsep dasar dalam pemrograman yang bertujuan untuk memisahkan antara definisi struktur data dan operasi yang boleh dilakukan tanpa perlu menunjukkan detail implementasi internal. Dalam bahasa C++, penerapan ADT umumnya dilakukan dengan memisahkan antara deklarasi tipe dan fungsinya dalam file header (.h) serta implementasinya dalam file (.cpp). Pemisahan ini bertujuan agar program lebih terstruktur, dan meminimalisir kesalahan saat terjadi perubahan pada satu bagian program.

## Guided 

### 1. Fungsi Deklarasi

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```
Kode diatas digunakan hanya untuk mendeklarasikan nama fungsi, parameter, dan tipe return-nya.

### 2. Fungsi dengan definisi lengkap

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m){
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 +m.nilai2) / 2.0;
}
```
Kode ini digunakan untuk menerima input data mahasiswa berupa NIM dan dua nilai, kemudian menghitung rata-rata dari nilai tersebut.

### 3. Fungsi utama

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
Kode di atas merupakan lanjutan dari nomor satu dan dua yang digunakan untuk menerima input data seorang mahasiswa, kemudian menghitung dan menampilkan rata-rata nilainya melalui pemanggilan fungsi inputMhs dan rata2.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas. 

```C++
#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, akhir;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa : ";
    cin >> n;
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "UTS : ";
        cin >> mhs[i].uts;
        cout << "UAS : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].akhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\nHASIL NILAI AKHIR\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Akhir : "<< mhs[i].akhir << endl;
    }

    return 0;
}

```
#### Output:
<img width="925" height="652" alt="Image" src="https://github.com/user-attachments/assets/a2550f5d-e60e-4550-bab7-30853250e249" />

Kode diatas digunakan untuk memasukkan data beberapa mahasiswa, lalu menghitung nilai akhirnya. Saat program dijalankan, kita mangisikan berapa jumlah mahasiswa yang ingin dimasukkan. Setelah itu, kita mengisi nama, NIM, nilai UTS, nilai UAS, dan nilai tugas untuk setiap mahasiswa.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:

<img width="1470" height="943" alt="Image" src="https://github.com/user-attachments/assets/d0f2c7aa-22f4-4672-8322-9e3ee953af68" />

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
#include <iostream>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif

#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}

#include "pelajaran.h"

int main() {
    pelajaran matematika = create_pelajaran("Bahasa Sunda", "SDA01");
    pelajaran fisika = create_pelajaran("Bahasa Jawa", "JWA02");

    tampil_pelajaran(matematika);
    cout << endl;
    tampil_pelajaran(fisika);

    return 0;
}
```
#### Output:
<img width="903" height="229" alt="Image" src="https://github.com/user-attachments/assets/acbdf6e5-e1c5-4b8b-8b03-4df9d4d1b343" />

Kode di atas digunakan untuk membuat dan menampilkan data mata pelajaran menggunakan konsep ADT (Abstract Data Type) / Struct dalam C++.

### 3. Buatlah program dengan ketentuan : 
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D 
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu 
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```
#### Output:
<img width="590" height="652" alt="Image" src="https://github.com/user-attachments/assets/2c5d452b-696f-4a75-9bf0-f29644b57e1b" />

Kode diatas digunakan untuk cara kerja array dua dimensi serta penggunaan fungsi dan pointer dalam bahasa C++. Pertama menampilkan isi array, kedua menunjukkan bagaimana dua buah array dapat saling menukar nilai pada posisi indeks tertentu, ketiga dimana variabel x dan y ditukar nilainya bukan secara langsung, tetapi dengan alamat memori.

#### Full code Screenshot:
<img width="2560" height="1600" alt="Image" src="https://github.com/user-attachments/assets/8b9a9050-2fe0-4144-b598-7f652fb24d25" />

## Kesimpulan
Menggunakan ADT memberikan banyak manfaat, terutama dalam hal keteraturan struktur program dan kemudahan pemeliharaan. Berdasarkan Modul yang diberikan pada praktikum ke 4, konsep ADT tidak hanya mengajarkan cara membuat struktur data, tetapi juga membentuk kebiasaan menulis program yang rapi dan terorganisir.

## Referensi
[1] Sianipar, R. H. (2014). Pemrograman C++ Untuk Pemula (Vol. 1). Penerbit INFORMATIKA.

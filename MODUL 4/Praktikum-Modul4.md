# <h1 align="center">Laporan Praktikum Modul 4 Tentang Singly Linked List (Bagian Pertama) (ADT)</h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

Singly Linked List merupakan salah satu bentuk struktur data dinamis yang terdiri dari kumpulan elemen atau node yang saling terhubung melalui pointer. Setiap node memiliki dua bagian utama, yaitu data yang menyimpan nilai, dan pointer next yang menunjuk ke node berikutnya dalam daftar. Berbeda dengan array, linked list memiliki ukuran yang tidak tetap (dinamis) dan memungkinkan penambahan serta penghapusan elemen tanpa perlu menggeser data lainnya. Dalam implementasi, pointer head digunakan untuk menandai node pertama dalam list, sedangkan node terakhir memiliki pointer next = NULL sebagai penanda akhir.

## Guided 

### 1. Header File
```C++

//header guard digunakan untuk mencegah file  header yang sama
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur; //tambahkan titik koma
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataMahasiswa isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { //Ini linked listnya
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev); // ✅ parameter diperbaiki
void insertLast(linkedList &List, address nodeBaru);

#endif

Bagian ini berisi deklarasi struct mahasiswa, node, dan linked list, serta daftar fungsi yang digunakan untuk mengelola data pada list.

### 2. Source File

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) { //ganti linkedlist -> linkedList
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Bagian ini berisi implementasi fungsi-fungsi dari header, seperti membuat list, menambah node, menghapus node, dan menampilkan isi list.

### 3. Main Program

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; //nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; //semua diinisialisasi Nil
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Bagian ini menjalankan proses utama program, yaitu membuat list, menambahkan data mahasiswa, dan menampilkan hasilnya ke layar.

## Unguided 

### 1. 
<img width="479" height="983" alt="Image" src="https://github.com/user-attachments/assets/6c0b3bfc-c264-4337-a6fc-0dcf18a22f6c" />

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

Kode di atas digunakan untuk melakukan perhitungan seperti penjumlahan, pengurangan, perkalian, dan pembagian.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). 
Output yang diharapkan :

<img width="861" height="157" alt="Image" src="https://github.com/user-attachments/assets/4be2fc03-2fa8-44f3-bfe3-77ec7d0ea334" />

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

Kode di atas digunakan untuk mengubah angka menjadi tulisan dengan penggunaan percabangan.

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
Modul ini memberikan pengenalan bahasa pemrograman C++ yang lumayan lengkap, dari struktur dasar program C++ yang meliputi deklarasi library, fungsi, dan program utama seperti variabel dan konstanta. Untuk input atau output terdapat penggunaan cout, cin, dan getchar dengan penjelasan format output yang tepat dalam membantu saya memahami logika pemrograman. Selain itu dengan adanya latihan soal yang terdapat modul juga sangat membantu saya melatih logika pemrograman dan penyelesaian masalahnya.
## Referensi
[1] Sianipar, R. H. (2012). Pemrograman C++: Dasar Pemrograman Berorientasi Objek (Vol. 1). Penerbit ANDI.

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
void insertAfter(linkedList &List, address nodeBaru, address Prev); 
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
A. HeaderFile

#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

using namespace std;

typedef int infotype;

struct ElmtList {
    infotype info;
    ElmtList *next;
};

struct List {
    ElmtList *first;
};

void createList(List &L);
ElmtList* alokasi(infotype x);
void dealokasi(ElmtList* P);
void insertFirst(List &L, ElmtList* P);
void printInfo(List L);

#endif

B. SourceFile

#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

ElmtList* alokasi(infotype x) {
    ElmtList *P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(ElmtList* P) {
    delete P;
}

void insertFirst(List &L, ElmtList* P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    ElmtList *P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

C. MainProgram

#include "SinglyList.h"

int main() {
    List L;
    ElmtList *P1, *P2, *P3, *P4, *P5;

    createList(L);

    P1 = alokasi(2);
    P2 = alokasi(0);
    P3 = alokasi(8);
    P4 = alokasi(12);
    P5 = alokasi(9);

    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);
    insertFirst(L, P4);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```
#### Output:
<img width="925" height="111" alt="Image" src="https://github.com/user-attachments/assets/be6c70f8-b312-4039-9da5-575e915f8a8d" />

Kode di atas digunakan untuk mengimplementasikan struktur data Singly Linked List (list berantai satu arah) dalam bahasa C++. Program ini bertujuan untuk menunjukkan bagaimana cara membuat list kosong, menambahkan elemen baru, dan menampilkan seluruh isi list menggunakan konsep pointer.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). 
Output yang diharapkan :

<img width="861" height="157" alt="Image" src="https://github.com/user-attachments/assets/4be2fc03-2fa8-44f3-bfe3-77ec7d0ea334" />

```C++
A. HeaderFile

#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* newNode(int value);
void insertFirst(List &L, Node* nodeBaru);
void printList(List L);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, int x);
int nbList(List L);
void deleteList(List &L);

#endif

B. SourceFile

#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

Node* newNode(int value) {
    Node* nodeBaru = new Node;
    nodeBaru->data = value;
    nodeBaru->next = NULL;
    return nodeBaru;
}

void insertFirst(List &L, Node* nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}

void printList(List L) {
    Node* bantu = L.first;
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node* bantu = L.first;
            Node* prev = NULL;
            while (bantu->next != NULL) {
                prev = bantu;
                bantu = bantu->next;
            }
            prev->next = NULL;
            delete bantu;
        }
    }
}

void deleteAfter(List &L, int x) {
    Node* bantu = L.first;
    while (bantu != NULL && bantu->next != NULL) {
        if (bantu->data == x) {
            Node* hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
            break;
        }
        bantu = bantu->next;
    }
}

int nbList(List L) {
    int count = 0;
    Node* bantu = L.first;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}


C. MainProgram

#include "SinglyList.h"

int main() {
    List L;
    createList(L);
    insertFirst(L, newNode(2));
    insertFirst(L, newNode(0));
    insertFirst(L, newNode(8));
    insertFirst(L, newNode(12));
    insertFirst(L, newNode(9));
    deleteFirst(L);     
    deleteLast(L);        
    deleteAfter(L, 12);   
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
#### Output:
<img width="920" height="189" alt="Image" src="https://github.com/user-attachments/assets/bfbb8566-2604-49b7-af15-373df21aba23" />

Kode di atas merupakan pengembangan dari ADT Single Linked sebelumnya, tapi ada tambahan beberapa fungsi untuk hapus data dan hitung jumlah node. Strukturnya masih pakai node dengan data dan pointer next. Bedanya, sekarang ada fungsi deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList. Jadi selain bisa nambah data lewat insertAwal, insertAkhir, dan insertAfter, program ini juga bisa hapus dan bersihin list.

#### Full code Screenshot:
<img width="2560" height="1600" alt="Image" src="https://github.com/user-attachments/assets/a6f2d7f3-6979-406d-b14e-a91245865a05" />

## Kesimpulan
Modul ini menjelaskan bahwa penggunaan singly linked list memberikan efisiensi dalam pengelolaan data yang sering berubah ukurannya. Misalnya, ketika diperlukan penambahan atau penghapusan data secara berulang, singly linked list jauh lebih efisien dibanding array karena tidak perlu melakukan pergeseran elemen. Namun, terdapat juga kelemahan seperti sulitnya melakukan akses langsung ke elemen tertentu karena pencarian harus dilakukan secara berurutan mulai dari node pertama.

## Referensi
[1] Sianipar, R. H. (2012). Pemrograman C++: Dasar Pemrograman Berorientasi Objek (Vol. 1). Penerbit ANDI.
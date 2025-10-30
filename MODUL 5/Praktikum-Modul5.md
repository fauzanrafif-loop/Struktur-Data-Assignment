# <h1 align="center">Laporan Praktikum Modul 5 Tentang Singly Linked List (Bagian Kedua) (ADT) </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

.........................................

## Guided 

### 1. Header File

```C++
//header guard digunakan untuk mencegah file  header yang sama
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct buah {
    string nama;
    string jumlah;
    int harga; //tambahkan titik koma
};

typedef buah dataBuah; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adaalah data & pointer next
    dataBuah isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { //Ini linked listnya
    address first;
};

//Semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

//Materi modul 5 (Part 1 - update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

//Materi modul 5 (part 2 - searching)
void FindNodeByData(linkedList List, string data);
void FindNoteByAddress(linkedList list, address node);
void FindNodeByRange(linkedList List, float hargaAwal, float hargaAkhir);

#endif
```

### 2. Source File

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    return (List.first == Nil);
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(!isEmpty(List)){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama 
                 << ", Jumlah : " << nodeBantu->isidata.jumlah 
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//----- MATERI MODUL 5 - UPDATE -----
void updateFirst(linkedList List){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//----- MATERI MODUL 5 - SEARCHING -----/
void FindNodeByData(linkedList List, string data){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama 
                     << ", Jumlah : " << nodeBantu->isidata.jumlah 
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(!found){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNoteByAddress(linkedList List, address node) { 
    if(isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama 
                     << ", Jumlah : " << nodeBantu->isidata.jumlah 
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(!found) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedList List, float hargaAwal, float hargaAkhir) {
    if(isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama 
                     << ", Jumlah : " << nodeBantu->isidata.jumlah 
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(!found) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 3. Main Program

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; //nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; //semua diinisialisasi Nil
    createList(List);

    // alokasi(name, jumlah, harga)
    nodeA = alokasi("Jeruk", "10", 5000);
    nodeB = alokasi("Semangka", "20", 6000);
    nodeC = alokasi("Pisang", "30", 7000);
    nodeD = alokasi("Anggur", "40", 8000);
    nodeE = alokasi("Alpukat", "50", 9000);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl; 
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Jeruk");
    FindNoteByAddress(List, nodeC); 
    FindNodeByRange(List, 5000, 6000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

## Unguided 

### 1. Latihan

<img width="484" height="1064" alt="Image" src="https://github.com/user-attachments/assets/e8078fd8-fff1-43d7-96e8-9bceff777eca" />

### Header file

```C++

#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &p);
void insertFirst(List &L, address p);
void printInfo(List L);
address findElm(List L, infotype x);
int sumInfo(List L);

#endif
```
### Source File 

```C++

#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address p = new elmlist;
    p->info = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void printInfo(List L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

address findElm(List L, infotype x) {
    address p = L.first;
    while (p != NULL) {
        if (p->info == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int sumInfo(List L) {
    int total = 0;
    address p = L.first;
    while (p != NULL) {
        total += p->info;
        p = p->next;
    }
    return total;
}
```

### Main Program

```C++

#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);
    printInfo(L);  

    address cari = findElm(L, 8);
    if (cari != NULL)
        cout << cari->info << " Ditemukan dalam list" << endl;
    else
        cout << "Tidak ditemukan dalam list" << endl;

    int total = sumInfo(L);
    cout << "Total info dari kelima elemen adalah: " << total << endl;

    return 0;
}
```
........................

Output 1.
<img width="148" height="20" alt="Image" src="https://github.com/user-attachments/assets/090c4657-dc88-4869-a15d-b4d2cc184e9a" />

Output 2.
<img width="263" height="29" alt="Image" src="https://github.com/user-attachments/assets/5f2995eb-7000-4f2d-9a95-47b13e154b66" />

Output 3.
<img width="456" height="24" alt="Image" src="https://github.com/user-attachments/assets/3faab646-66f8-430b-8947-aa11ba38e270" />

#### Full code Screenshot:
...................................

## Kesimpulan
..........................................

## Referensi
[1] ..................................
#include <iostream>
#include "doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype data;
    string cari, hapus;
    address P;

    int count = 0;

    while(count < 4) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;

        bool duplicate = (findElm(L, data.nopol) != Nil);

        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        if (duplicate) {
            cout << "nomor polisi sudah terdaftar\n\n";
        } else {
            P = alokasi(data);
            insertLast(L, P);
            cout << endl;
        }

        count++;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> cari;
    cout << endl;
    searchAndPrintAll(L, cari);
    cout << endl;

    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> hapus;
    cout << endl;

    int deleted = deleteAllMatches(L, hapus);

    if(deleted > 0)
        cout << "Data dengan nomor polisi" << hapus << " berhasil dihapus." << endl;
    else
        cout << "Data tidak ditemukan." << endl;

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}

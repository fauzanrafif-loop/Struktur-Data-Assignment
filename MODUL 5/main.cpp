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

#include <iostream>
#include "singlylist.h"
using namespace std;

int main() {
    list L;
    createList(L); // inisialisasi list kosong

    // Membuat node baru
    node *P1 = newNode(2);
    node *P2 = newNode(0);
    node *P3 = newNode(8);
    node *P4 = newNode(12);
    node *P5 = newNode(9);

    // Menyisipkan node ke dalam list
    insertFirst(L, P1);
    insertFirst(L, P2);
    insertFirst(L, P3);
    insertFirst(L, P4);
    insertFirst(L, P5);

    cout << endl;
    show(L);
    cout << endl;
    node *found = findElm(L, 8);
    if (found != NULL)
        cout << "8 ditemukan dalam list." << endl;
    else
        cout << "8 tidak ditemukan dalam list." << endl;

    cout << endl;
    cout << "Total info dari kelima elemen adalah: " << Info(L) << endl;
    cout << endl;

    return 0;
}

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

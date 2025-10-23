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
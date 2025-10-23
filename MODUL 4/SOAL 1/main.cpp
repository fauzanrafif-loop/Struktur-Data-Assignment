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

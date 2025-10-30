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

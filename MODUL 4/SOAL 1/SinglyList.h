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

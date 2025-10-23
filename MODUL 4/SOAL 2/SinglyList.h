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
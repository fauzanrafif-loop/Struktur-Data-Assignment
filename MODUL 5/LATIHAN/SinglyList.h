#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

struct list {
    node *first;
};

void createList(list &L);
node* newNode(int x);
void insertFirst(list &L, node *n);
void insertLast(list &L, node *n);
void insertAfter(node *prev, node *n);
void show(list L);

void deleteFirst(list &L);
void deleteLast(list &L);
void deleteAfter(node *prev);
int nbList(list L);
void deleteList(list &L);
node* findElm(list L, int x);
int Info(list L);

#endif
#include "singlylist.h"
#include <iostream>
using namespace std;

void createList(list &L){
    L.first = NULL;
}

node* newNode(int x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    return n;
}

void insertFirst(list &L, node *n){
    if(L.first == NULL) L.first = n;
    else {
        n->next = L.first;
        L.first = n;
    }
}

void insertLast(list &L, node *n){
    if(L.first == NULL) L.first = n;
    else {
        node *p = L.first;
        while(p->next != NULL) p = p->next;
        p->next = n;
    }
}

void insertAfter(node *prev, node *n){
    if(prev != NULL){
        n->next = prev->next;
        prev->next = n;
    }
}

void show(list L){
    node *p = L.first;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteFirst(list &L){
    if(L.first != NULL){
        node *p = L.first;
        L.first = p->next;
        delete p;
    }
}

void deleteLast(list &L){
    if(L.first != NULL){
        node *p = L.first;
        node *q = NULL;
        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        if(q == NULL) L.first = NULL;
        else q->next = NULL;
        delete p;
    }
}

void deleteAfter(node *prev){
    if(prev != NULL && prev->next != NULL){
        node *p = prev->next;
        prev->next = p->next;
        delete p;
    }
}

int nbList(list L){
    int n = 0;
    node *p = L.first;
    while(p != NULL){
        n++;
        p = p->next;
    }
    return n;
}

void deleteList(list &L){
    node *p = L.first;
    while(p != NULL){
        node *tmp = p;
        p = p->next;
        delete tmp;
    }
    L.first = NULL;
}

node* findElm(list L, int x){
    node *p = L.first;
    while(p != NULL && p->data != x){
        p = p->next;
    }
    return p;
}

int Info(list L){
    int total = 0;
    node *p = L.first;
    while(p != NULL){
        total += p->data;
        p = p->next;
    }
    return total;
}
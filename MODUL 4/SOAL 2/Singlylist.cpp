#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

Node* newNode(int value) {
    Node* nodeBaru = new Node;
    nodeBaru->data = value;
    nodeBaru->next = NULL;
    return nodeBaru;
}

void insertFirst(List &L, Node* nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}

void printList(List L) {
    Node* bantu = L.first;
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node* hapus = L.first;
        L.first = L.first->next;
        delete hapus;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node* bantu = L.first;
            Node* prev = NULL;
            while (bantu->next != NULL) {
                prev = bantu;
                bantu = bantu->next;
            }
            prev->next = NULL;
            delete bantu;
        }
    }
}

void deleteAfter(List &L, int x) {
    Node* bantu = L.first;
    while (bantu != NULL && bantu->next != NULL) {
        if (bantu->data == x) {
            Node* hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
            break;
        }
        bantu = bantu->next;
    }
}

int nbList(List L) {
    int count = 0;
    Node* bantu = L.first;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}

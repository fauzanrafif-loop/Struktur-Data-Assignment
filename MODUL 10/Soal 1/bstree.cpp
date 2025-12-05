#include <iostream>
#include "bstree.h"

using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil)
        return Nil;

    if (x == root->info)
        return root;
    else if (x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

void printInOrder(address root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

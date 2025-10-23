#include "SinglyList.h"

int main() {
    List L;
    createList(L);
    insertFirst(L, newNode(2));
    insertFirst(L, newNode(0));
    insertFirst(L, newNode(8));
    insertFirst(L, newNode(12));
    insertFirst(L, newNode(9));
    deleteFirst(L);     
    deleteLast(L);        
    deleteAfter(L, 12);   
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

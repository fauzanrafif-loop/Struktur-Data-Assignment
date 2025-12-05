# <h1 align="center">Laporan Praktikum Modul 10 tentang Tree Bagian Pertama </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

Fungsi rekursif, Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar. Selanjutnya masuk ke bagian Tree, Tree adalah struktur data non-linear yang tersusun atas sekumpulan node yang saling terhubung secara hierarkis. Pada struktur tree terdapat satu node khusus yang disebut root, yaitu node yang tidak memiliki parent, sementara node lain masing-masing hanya memiliki satu parent. Tree tidak mengandung siklus dan memiliki jalur unik dari root ke setiap node lainnya. Node yang memiliki anak disebut internal node, sedangkan node yang tidak memiliki anak disebut leaf. Terdapat jenis-jenis tree yang pertama ada Ordered Tree dan Binary Tree keduanya berbeda untuk Ordered Tree sendiri anak-anaknya atau child itu berpengaruh semua, sedangkan Binary Tree setiap nodenya hanya memiliki maksimum dua anak atau child. Pada Binary Tree ada berbagai jenisnya yaitu :
-	Complete Binary Tree
-	Extended Binary Tree
-	Binary Search Tree
-	AVL Tree
-	Heap Tree
Selanjutnya ada operasi-operasi dalam Binary Search Tree yaitu:
-	Insert
-	Update
-	Search
-	Delete
-	Most Left
-	Most right

## Guided 

### 1. Header File

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

### 2. Source File

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksaaaudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}


bool deleteNode(BinTree tree, int angka){
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

### 3. Main Program

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

## Unguided 

### Soal Latihan

### 1.  Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:

<img width="971" height="955" alt="Image" src="https://github.com/user-attachments/assets/206c9756-4aeb-4a63-aabb-fb1e027b3850" />

### Header File
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;

typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInOrder(address root);

#endif

```

### Source File
```C++
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

```

### Main Program
```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);

    printInOrder(root);

    return 0;
}

```

Kode diatas digunakan untuk mengimplementasikan cara kerja Binary Search Tree menggunakan Linked List.

#### Output:

<img width="325" height="56" alt="Image" src="https://github.com/user-attachments/assets/0bfd671e-2159-4461-840c-4c0f21fd7ece" />

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.

 - fungsihitungJumlahNode( root:address ) : integer /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
 - fungsihitungTotalInfo( root:address, start:integer ) : integer /* fungsi mengembalikan jumlah (total) info dari node-node yang  ada di dalam BST*/
 - fungsihitungKedalaman( root:address, start:integer ) : integer /* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

 <img width="893" height="610" alt="Image" src="https://github.com/user-attachments/assets/bd1aa462-5c89-4f62-8a65-45175221ae9f" />

### Header File
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```

### Source File
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong atau Tidak ada" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root){ 
    if(root == Nil){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
    cout << endl;
}

int hitungTotalInfo(address root, int start){
    if (root == Nil){
        return 0;
    } else {
        int total = root->info;
        return total + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}

int hitungKedalaman(address root, int start){
    if (root == Nil){
        return start;
    } else {
        int h1 = hitungKedalaman(root->left, start + 1);
        int h2 = hitungKedalaman(root->right, start + 1);
        int maxHeight;
        if (h1 > h2){
            maxHeight = h1;
        } else {
            maxHeight = h2;
        }
        return maxHeight;
    }
}
```

### Main Program
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInorder(root);
    cout << "\n";
    cout << "Kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root, 0) << endl;
    return 0;
}
```

Kode di atas digunakan untuk melakukan perhitungan rekursif pada struktur data Binary Search Tree

#### Output:

<img width="317" height="130" alt="Image" src="https://github.com/user-attachments/assets/f40cad4b-cdc8-4800-b6e4-c28b02e67deb" />

### 3.  Print tree secara pre-order dan post-order.

<img width="738" height="399" alt="Image" src="https://github.com/user-attachments/assets/874ce00d-5a46-4395-817a-990ed336b33c" />

### Header File
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
void preOrder(address root);
void postOrder(address root);

#endif
```

### Source File
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong atau Tidak Ada" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

```

### Main Program
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    cout << "pre-order : " ;
             preOrder(root); 
             cout << endl;
    cout << "post-order : "; 
             postOrder(root);
             cout << endl;
    return 0;
}
```
Kode diatas digunakan untuk menampilkan hasil print Tree secara pre-order dan post-order 

#### Output:

<img width="544" height="108" alt="Image" src="https://github.com/user-attachments/assets/550e6ad9-bee7-4523-93e4-d7d5263bfd6a" />

#### Full code Screenshot:

<img width="2560" height="1600" alt="Image" src="https://github.com/user-attachments/assets/028d20a8-7d78-4248-9652-f5a008499ea3" />

## Kesimpulan

Pada Modul 12 ini kita pakai rekursif untuk menyelesaikan masalah yang bisa dipecah jadi bagian-bagian serupa, misalnya menghitung faktorial atau pangkat dan juga fokus pada Binary Search Tree (BST), di mana setiap simpul punya paling banyak dua anak, dan posisinya diatur agar pencarian data jadi lebih cepat. Selain itu kita juga mencoba menambahkan data ke BST(Binary Search Tree), mencari dan menghapus data serta melakukan traversal (pre-order, in-order, post-order).

## Referensi
[1] Rahmawati, E., Medina, P., & Azhari, D. S. (2024). Rekursif Dalam Pemrograman Teori Dan Praktek. Innovative: Journal Of Social Science Research, 4(4), 5622-5630.
[2] Wisesty, U. N., Nurrahmi, H., Yunanto, P. E., Rismala, R., & Sthevanie, F. (2025). STRUKTUR DATA MENGGUNAKAN C++. PENERBIT KBM INDONESIA.
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "List Graph" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "Hasil penelusuran menggunakan DFS" << endl;
    PrintDFS(G, A);
    cout << endl;

    cout << "Hasil penelusuran menggunakan BFS" << endl;
    PrintBFS(G, A);
    cout << endl;
}
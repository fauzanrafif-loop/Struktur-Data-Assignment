#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    char op;

    cout << "Masukkan matriks A :\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> A[i][j];

    cout << "Masukkan matriks B :\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> B[i][j];

    cout << "Pilih operasi hitung: ";
    cin >> op;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(op == '+') C[i][j] = A[i][j] + B[i][j];
            else if(op == '-') C[i][j] = A[i][j] - B[i][j];
            else if(op == '*'){
                C[i][j] = 0;
                for(int k=0;k<3;k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
}

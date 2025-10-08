#include <iostream>

using namespace std;

void Pointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void Reference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai: ";
    cin >> x >> y >> z;
    cout << "Nilai awal: " << x << " " << y << " " << z << endl;

    Pointer(&x, &y, &z);
    cout << "Pointer : " << x << " " << y << " " << z << endl;

    Reference(x, y, z);
    cout << "Reference : " << x << " " << y << " " << z << endl;

    return 0;
}
# <h1 align="center">Laporan Praktikum Modul 2 Pengenalan Bahasa C++ (Bagian Kedua) </h1>
<p align="center">Fauzan Rafif - 103112400227</p>

## Dasar Teori

Modul ini membahas array, pointer, fungsi, dan prosedur. Array didefinisikan sebagai kumpulan data dengan tipe yang sama yang disimpan dalam lokasi memori berurutan, dengan kemampuan akses melalui indeks.Kalau pointer sangat terkait dengan array karena nama array sendiri merupakan pointer ke elemen pertama array tersebut. Sedangkan fungsi dan prosedur merupakan kode yang dirancang untuk melakukan tugas spesifik, dengan perbedaan utama bahwa fungsi mengembalikan nilai sedangkan prosedur tidak.

## Guided 

### 1. Array

```C++
#include <iostream>

using namespace std;

int main(){
    int arr1D[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" <<  endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
    }
    cout << endl;

    // Array Multi Dimensi (2D)
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Array Multi Dimensi (3D)
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };
    cout << "Array 3 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Kode diatas digunakan untuk menampilkan isi array satu dimensi, dua dimensi, dan tiga dimensi.

### 2. Prosedur

```C++
#include <iostream>

using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}

int main(){
    int jum;
    cout << "Jumlah Baris Kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
Kode diatas digunakan untuk menampilkan sejumlah baris teks sesuai dengan angka yang kita masukkan.

### 3. Pointer
```C++
#include <iostream>

using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main (){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of a : " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl;

    return 0;
}
```
Kode diatas digunakan untuk menunjukkan cara kerja pointer dan fungsi pertukaran nilai menggunakan pointer.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
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
```
#### Output:
<img width="1746" height="915" alt="Image" src="https://github.com/user-attachments/assets/a0999adf-3763-406a-bd07-144617aa2ec9" />

Kode di atas digunakan untuk melakukan operasi dasar pada dua matriks berukuran 3x3, yaitu penjumlahan, pengurangan, dan perkalian.Kita diminta untuk memasukkan nilai-nilai dari dua matriks, yaitu matriks A dan matriks B. Setelah kedua matriks dimasukkan, kita memilih jenis operasi yang ingin dilakukan seperti penjumlahan dengan menggunakan simbol +, pengurangan dengan simbol - dan perkalian dengan simbol *.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
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
```
#### Output:
<img width="1357" height="142" alt="Image" src="https://github.com/user-attachments/assets/fcf73886-8e6e-4946-a46f-87c6f2d9ad3d" />

Kode di atas digunakan untuk menukar nilai dari tiga variabel dengan menggunakan dua cara berbeda, yaitu pointer dan reference.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : 
### arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : 
--- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata

```C++
#include <iostream>

using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] < min) min = arr[i];
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > max) max = arr[i];
    return max;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for(int i=0; i<n; i++)
        total += arr[i];
    cout << "Nilai rata-rata: " << total / n << endl;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10, menu;

    cout << "--- Menu Program Array ---\n";
    cout << "1. Tampilkan isi array\n";
    cout << "2. Cari nilai maksimum\n";
    cout << "3. Cari nilai minimum\n";
    cout << "4. Hitung nilai rata-rata\n";
    cout << "Pilih salah satu menu diatas: ";
    cin >> menu;

    switch(menu) {
        case 1:
            cout << "Masukkan isi array: ";
            for(int i=0; i<n; i++) cout << arrA[i] << " ";
            cout << endl;
            break;
        case 2:
            cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
            break;
        case 3:
            cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
            break;
        case 4:
            hitungRataRata(arrA, n);
            break;
    }
}
```
#### Output:
<img width="1665" height="898" alt="Image" src="https://github.com/user-attachments/assets/13943e91-707a-4782-9fef-5e4f7db60b5d" />

Kode di atas digunakan untuk mengolah data dalam sebuah array satu dimensi dengan menampilkan nilai maksimum, minimum, dan nilai rata-rata, serta isi dari array itu sendiri.

#### Full code Screenshot:
<img width="2560" height="1600" alt="Image" src="https://github.com/user-attachments/assets/01560097-d8d5-4937-958d-6a3cc1c87fbe" />

## Kesimpulan
Modul ini merupakan lanjutan yang berfokus pada ide array, pointer, fungsi, dan prosedur. Pengetahuan yang mendalam mengenai array membuat pengaturan data menjadi lebih sistematis, sedangkan penguasaan pointer memberikan peluang untuk pengolahan memori yang lebih efektif. Fungsi dan prosedur tuh bikin kita lebih gampang daripada harus nulis kode yang sama berulang-ulang, mending dibikin sekali trus dipanggil berkali-kali.

## Referensi
[1] Putra, M. T. D., Munawir, M., & Yuniarti, A. R. (2023). BELAJAR PEMROGRAMAN LANJUT DENGAN C++.

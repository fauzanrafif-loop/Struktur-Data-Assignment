#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
#include <iostream>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif

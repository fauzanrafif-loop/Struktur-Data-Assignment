#include "pelajaran.h"

int main() {
    pelajaran matematika = create_pelajaran("Bahasa Sunda", "SDA01");
    pelajaran fisika = create_pelajaran("Bahasa Jawa", "JWA02");

    tampil_pelajaran(matematika);
    cout << endl;
    tampil_pelajaran(fisika);

    return 0;
}

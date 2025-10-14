#include "pelajaran.h"

int main() {
    pelajaran matematika = create_pelajaran("Matematika", "MTH101");
    pelajaran fisika = create_pelajaran("Fisika", "PHY102");

    tampil_pelajaran(matematika);
    cout << endl;
    tampil_pelajaran(fisika);

    return 0;
}

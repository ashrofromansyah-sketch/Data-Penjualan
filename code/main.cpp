#include "mll.h"

int main() {
    ListToko LT;
    ListBarang LB;
    createListToko(LT);
    createListBarang(LB);

    int choice;
    do {
        cout << "\n=== MENU DATA PENJUALAN ===\n";
        cout << "1. Insert Toko\n";
        cout << "2. Tampilkan Toko\n";
        cout << "3. Insert Barang\n";
        cout << "4. Hubungkan Toko & Barang\n";
        cout << "5. Tampilkan Toko & Barang\n";
        cout << "6. Hitung Barang di Toko\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id, nama;
            cout << "ID Toko: "; getline(cin, id);
            cout << "Nama Toko: "; getline(cin, nama);
            insertLastToko(LT, id, nama);
        }
        else if (choice == 2) {
            showAllToko(LT);
        }
        else if (choice == 3) {
            string id, nama;
            cout << "ID Barang: "; getline(cin, id);
            cout << "Nama Barang: "; getline(cin, nama);
            insertLastBarang(LB, id, nama);
        }
        else if (choice == 4) {
            string idT, idB;
            cout << "ID Toko: "; getline(cin, idT);
            cout << "ID Barang: "; getline(cin, idB);
            Toko* t = findToko(LT, idT);
            Barang* b = findBarang(LB, idB);
            if (t && b)
                addRelasi(t, b);
            else
                cout << "Toko atau Barang tidak ditemukan\n";
        }
        else if (choice == 5) {
            showTokoAndBarang(LT);
        }
        else if (choice == 6) {
            string idT;
            cout << "ID Toko: "; getline(cin, idT);
            Toko* t = findToko(LT, idT);
            if (t)
                cout << "Jumlah Barang: " << countBarangInToko(t) << endl;
        }

    } while (choice != 0);

    return 0;
}


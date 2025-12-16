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

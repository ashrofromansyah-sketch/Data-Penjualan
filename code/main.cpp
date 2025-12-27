#include "mll.h"
#include <iostream>
using namespace std;

int main() {
    ListToko LT;
    ListBarang LB;
    createListToko(LT);
    createListBarang(LB);

    int choice;

    do {
        cout << "\n=================================\n";
        cout << "        MENU DATA PENJUALAN       \n";
        cout << "=================================\n";
        cout << "1. Insert Toko\n";
        cout << "2. Tampilkan Toko atau Barang\n";
        cout << "3. Insert Barang\n";
        cout << "4. Buat Relasi\n";
        cout << "5. Tampilkan Toko & Barang\n";
        cout << "6. Hitung Barang di Toko\n";
        cout << "7. Cari Toko atau Barang\n";
        cout << "8. Cari Relasi\n";
        cout << "9. Toko Menjual Barang\n";
        cout << "10. Barang Dijual di Toko\n";
        cout << "11. Hapus Toko atau Barang\n";
        cout << "12. Hapus Relasi Toko & Barang\n";
        cout << "0. Keluar\n";
        cout << "=================================\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();

        cout << "\n---------------------------------\n";

        /* ========== INSERT TOKO ========== */
        if (choice == 1) {
            string id, nama, pilih;
            double rating;

            cout << "ID Toko           : "; getline(cin, id);
            cout << "Nama Toko         : "; getline(cin, nama);
            cout << "Rating Toko (0-5) : ";
            cin >> rating;
            cin.ignore();

            if (rating < 0) rating = 0;
            if (rating > 5) rating = 5;

            cout << "Simpan di awal atau akhir? (f/l): ";
            getline(cin, pilih);

            if (pilih == "f" || pilih == "F") {
                insertFirstToko(LT, id, rating, nama);
                cout << "✔ Toko berhasil ditambahkan di AWAL\n";
            }
            else if (pilih == "l" || pilih == "L") {
                insertLastToko(LT, id, rating, nama);
                cout << "✔ Toko berhasil ditambahkan di AKHIR\n";
            }
            else {
                cout << "✘ Pilihan tidak valid, data tidak disimpan\n";
            }

            cout << "\n=== DAFTAR TOKO TERKINI ===\n";
            showAllToko(LT);
        }

        else if (choice == 2) {
            string pilih;
            cout << "Tampilkan Toko atau Barang? (t/b): ";
            getline(cin, pilih);

            if (pilih == "t" || pilih == "T") {
                cout << "\n=== DAFTAR TOKO ===\n";
                showAllToko(LT);
            }
            else if (pilih == "b" || pilih == "B") {
                cout << "\n=== DAFTAR BARANG ===\n";
                showAllBarang(LB);
            }
            else {
                cout << "✘ Pilihan tidak valid\n";
            }
        }

        else if (choice == 3) {
            string id, nama, pilih;
            int harga;

            cout << "ID Barang   : "; getline(cin, id);
            cout << "Nama Barang : "; getline(cin, nama);
            cout << "Harga       : ";
            cin >> harga;
            cin.ignore();

            if (harga < 0) harga = 0;

            cout << "Simpan di awal atau akhir? (f/l): ";
            getline(cin, pilih);

            if (pilih == "f" || pilih == "F") {
                insertFirstBarang(LB, id, harga, nama);
                cout << "✔ Barang berhasil ditambahkan di AWAL\n";
            }
            else if (pilih == "l" || pilih == "L") {
                insertLastBarang(LB, id, harga, nama);
                cout << "✔ Barang berhasil ditambahkan di AKHIR\n";
            }
            else {
                cout << "✘ Pilihan tidak valid, barang tidak disimpan\n";
            }

            cout << "\n=== DAFTAR BARANG TERKINI ===\n";
            showAllBarang(LB);
        }

        else if (choice == 4) {
            string idT, idB;
            cout << "ID Toko   : "; getline(cin, idT);
            cout << "ID Barang : "; getline(cin, idB);

            Toko* t = findToko(LT, idT);
            Barang* b = findBarang(LB, idB);

            if (t && b) {
                addRelasi(t, b);
                cout << "✔ Relasi berhasil dibuat\n";
            } else {
                cout << "✘ Toko atau Barang tidak ditemukan\n";
            }
        }

        else if (choice == 5) {
            cout << "\n=== TOKO DAN BARANG YANG DIJUAL ===\n";
            showTokoAndBarang(LT);
        }

        else if (choice == 6) {
            string idT;
            cout << "ID Toko: "; getline(cin, idT);

            Toko* t = findToko(LT, idT);
            if (t) {
                cout << "✔ Jumlah barang di "
                     << t->namaToko << " : "
                     << countBarangInToko(t) << endl;
            } else {
                cout << "✘ Toko tidak ditemukan\n";
            }
        }

        else if (choice == 7) {
            string pilih, key;
            cout << "Cari Toko atau Barang? (t/b): ";
            getline(cin, pilih);

            if (pilih == "t" || pilih == "T") {
                cout << "ID Toko: "; getline(cin, key);
                Toko* t = findToko(LT, key);
                if (t) cout << "✔ Toko ditemukan: " << t->namaToko << endl;
                else cout << "✘ Toko tidak ditemukan\n";
            }
            else if (pilih == "b" || pilih == "B") {
                cout << "ID Barang: "; getline(cin, key);
                Barang* b = findBarang(LB, key);
                if (b) cout << "✔ Barang ditemukan: " << b->namaBarang << endl;
                else cout << "✘ Barang tidak ditemukan\n";
            }
        }

        else if (choice == 8) {
            string idT, idB;
            cout << "ID Toko   : "; getline(cin, idT);
            cout << "ID Barang : "; getline(cin, idB);

            Toko* t = findToko(LT, idT);
            Barang* b = findBarang(LB, idB);

            if (t && b) {
                if (findRelasi(t, b))
                    cout << "✔ Relasi ditemukan\n";
                else
                    cout << "✘ Relasi tidak ditemukan\n";
            }
        }

        else if (choice == 9) {
            string idB;
            cout << "ID Barang: "; getline(cin, idB);
            cout << "\n=== TOKO YANG MENJUAL BARANG ===\n";
            tokoMenjualBarang(LT, idB);
        }

        else if (choice == 10) {
            string idT;
            cout << "ID Toko: "; getline(cin, idT);
            cout << "\n=== BARANG YANG DIJUAL TOKO ===\n";
            barangDijualToko(LT, idT);
        }

        else if (choice == 11) {
            string pilih, id;
            cout << "Hapus Toko atau Barang? (t/b): ";
            getline(cin, pilih);

            if (pilih == "t" || pilih == "T") {
                cout << "ID Toko: "; getline(cin, id);
                deleteToko(LT, id);
                cout << "✔ Proses hapus toko selesai\n";
            }
            else if (pilih == "b" || pilih == "B") {
                cout << "ID Barang: "; getline(cin, id);
                deleteBarang(LB, id);
                cout << "✔ Proses hapus barang selesai\n";
            }
        }

        else if (choice == 12) {
            string idT, idB;
            cout << "ID Toko   : "; getline(cin, idT);
            cout << "ID Barang : "; getline(cin, idB);

            Toko* t = findToko(LT, idT);
            Barang* b = findBarang(LB, idB);

            if (t && b) {
                deleteRelasi(t, b);
                cout << "✔ Relasi berhasil dihapus\n";
            }
        }

        else if (choice == 0) {
            cout << "Keluar dari program...\n";
        }

        else {
            cout << "✘ Menu tidak valid\n";
        }

    } while (choice != 0);

    return 0;
}

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
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id, nama, pilih;
            double rating;
            cout << "ID Toko: "; getline(cin, id);
            cout << "Nama Toko: "; getline(cin, nama);
            cout << "Rating Toko: ";
            cin >> rating;
            if (rating < 0.0) rating = 0.0;
            if (rating > 5.0) rating = 5.0;
            cout << "Simpan di awal atau akhir? (f/l): "; getline(cin, pilih);
            if (pilih == "f" || pilih == "F") {
                insertFirstToko(LT, id, rating, nama);
            } else if (pilih == "l" || pilih == "L") {
                insertLastToko(LT, id, rating, nama);
            } else {
                cout << "Pilihan tidak valid\n";
            }
        }
        else if (choice == 2) {
            string pilih;
            cout << "Tampilkan Toko atau Barang? (t/b): "; getline(cin, pilih);
            if (pilih == "t" || pilih == "T") {
                showAllToko(LT);
            } else if (pilih == "b" || pilih == "B") {
                showAllBarang(LB);
            } else {
                cout << "Pilihan tidak valid\n";
            }
        }
        else if (choice == 3) {
            string id, nama, pilih;
            int harga;
            cout << "ID Barang: "; getline(cin, id);
            cout << "Nama Barang: "; getline(cin, nama);
            cout << "Harga Barang: ";
            cin >> harga;
            if (harga < 0) harga = 0;
            cout << "Simpan di awal atau akhir? (f/l): "; getline(cin, pilih);
            if (pilih == "f" || pilih == "F") {
                insertFirstBarang(LB, id, harga, nama);
            } else if (pilih == "l" || pilih == "L") {
                insertLastBarang(LB, id, harga, nama);
            } else {
                cout << "Pilihan tidak valid\n";
            }
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
        else if (choice == 7) {
            string pilih, key;
            cout << "Cari Toko atau Barang? (t/b): "; getline(cin, pilih);
            if (pilih == "t" || pilih == "T") {
                cout << "ID Toko: "; getline(cin, key);
                Toko* t = findToko(LT, key);
                if (t)
                    cout << "Toko Ditemukan: " << t->namaToko << endl;
                else
                    cout << "Toko tidak ditemukan\n";
            } else if (pilih == "b" || pilih == "B") {
                cout << "ID Barang: "; getline(cin, key);
                Barang* b = findBarang(LB, key);
                if (b)
                    cout << "Barang Ditemukan: " << b->namaBarang << endl;
                else
                    cout << "Barang tidak ditemukan\n";
            } else {
                cout << "Pilihan tidak valid\n";
            }
        }
        else if (choice == 8) {
            string idT, idB;
            cout << "ID Toko: "; getline(cin, idT);
            cout << "ID Barang: "; getline(cin, idB);
            Toko* t = findToko(LT, idT);
            Barang* b = findBarang(LB, idB);
            if (t && b) {
                Relasi* r = findRelasi(t, b);
                if (r)
                    cout << "Relasi Ditemukan\n";
                else
                    cout << "Relasi tidak ditemukan\n";
            } else {
                cout << "Toko atau Barang tidak ditemukan\n";
            }
        }
        else if (choice == 9) {
            string idB;
            cout << "ID Barang: "; getline(cin, idB);
            tokoMenjualBarang(LT, idB);
        }
        else if (choice == 10) {
            string idT;
            cout << "ID Toko: "; getline(cin, idT);
            barangDijualToko(LT, idT);
        }
        else if (choice == 11) {
            string pilih, id;
            cout << "Hapus Toko atau Barang? (t/b): "; getline(cin, pilih);
            if (pilih == "t" || pilih == "T") {
                cout << "ID Toko: "; getline(cin, id);
                deleteToko(LT, id);
            } else if (pilih == "b" || pilih == "B") {
                cout << "ID Barang: "; getline(cin, id);
                deleteBarang(LB, id);
            } else {
                cout << "Pilihan tidak valid\n";
            }
        }
        else if (choice == 12) {
            string idT, idB;
            cout << "ID Toko: "; getline(cin, idT);
            cout << "ID Barang: "; getline(cin, idB);
            Toko* t = findToko(LT, idT);
            Barang* b = findBarang(LB, idB);
            if (t && b)
                deleteRelasi(t, b);
            else
                cout << "Toko atau Barang tidak ditemukan\n";
        }

    } while (choice != 0);

    return 0;
}


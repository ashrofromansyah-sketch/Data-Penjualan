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
        cout << "4. Buat Relasi Toko & Barang\n";
        cout << "5. Tampilkan Toko & Barang\n";
        cout << "6. Hitung Barang di Toko\n";
        cout << "7. Cari Toko atau Barang\n";
        cout << "8. Toko Menjual Barang\n";
        cout << "9. Barang Dijual di Toko\n";
        cout << "10. Hapus Toko atau Barang\n";
        cout << "11. Hapus Relasi Toko & Barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id, nama, pilih;
            double rating;
            cout << "ID Toko: "; getline(cin, id);
            cout << "Nama Toko: "; getline(cin, nama);
            cout << "Rating Toko: "; getline(cin, rating);
            if (rating < 0.0) rating = 0.0;
            if (rating > 5.0) rating = 5.0;
            cout << "Simpan di awal atau akhir? (f/l): "; getline(cin, pilih);
            if (pilih == "f" || pilih == "F") {
                insertFirstToko(LT, id, nama, rating);
            } else if (pilih == "l" || pilih == "L") {
                insertLastToko(LT, id, nama, rating);
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
            cout << "Harga Barang: "; getline(cin, harga);
            if (harga < 0) harga = 0;
            cout << "Simpan di awal atau akhir? (f/l): "; getline(cin, pilih);
            if (pilih == "f" || pilih == "F") {
                insertFirstBarang(LB, id, nama, harga);
            } else if (pilih == "l" || pilih == "L") {
                insertLastBarang(LB, id, nama, harga);
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

    } while (choice != 0);

    return 0;
}


#include "mll.h"

int main()
{
    ListToko LT;
    ListBarang LB;
    createListToko(LT);
    createListBarang(LB);

    int choice;
    do
    {
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

        // ================= INSERT TOKO =================
        if (choice == 1)
        {
            string id, nama, pilih;
            double rating;

            cout << "ID Toko   : ";
            getline(cin, id);
            cout << "Nama Toko : ";
            getline(cin, nama);
            cout << "Rating    : ";
            cin >> rating;
            cin.ignore();

            if (rating < 0)
                rating = 0;
            if (rating > 5)
                rating = 5;

            cout << "Simpan di awal atau akhir? (f/l): ";
            getline(cin, pilih);

            if (pilih == "f" || pilih == "F")
            {
                insertFirstToko(LT, id, rating, nama);
                cout << "\nToko berhasil ditambahkan di AWAL\n";
            }
            else if (pilih == "l" || pilih == "L")
            {
                insertLastToko(LT, id, rating, nama);
                cout << "\nToko berhasil ditambahkan di AKHIR\n";
            }
            else
            {
                cout << "Pilihan tidak valid\n";
                continue;
            }

            // === OUTPUT LANGSUNG TOKO YANG DIINSERT ===
            Toko *t = findToko(LT, id);
            if (t)
            {
                cout << "=== DATA TOKO ===\n";
                cout << "ID     : " << t->idToko << endl;
                cout << "Nama   : " << t->namaToko << endl;
                cout << "Rating : " << t->ratingToko << endl;
            }
        }

        else if (choice == 2)
        {
            string pilih;
            cout << "Tampilkan Toko atau Barang? (t/b): ";
            getline(cin, pilih);
            if (pilih == "t" || pilih == "T")
                showAllToko(LT);
            else if (pilih == "b" || pilih == "B")
                showAllBarang(LB);
            else
                cout << "Pilihan tidak valid\n";
        }

        else if (choice == 3)
        {
            string id, nama, pilih;
            int harga;
            cout << "ID Barang   : ";
            getline(cin, id);
            cout << "Nama Barang : ";
            getline(cin, nama);
            cout << "Harga       : ";
            cin >> harga;
            cin.ignore();

            if (harga < 0)
                harga = 0;

            cout << "Simpan di awal atau akhir? (f/l): ";
            getline(cin, pilih);

            if (pilih == "f" || pilih == "F")
                insertFirstBarang(LB, id, harga, nama);
            else if (pilih == "l" || pilih == "L")
                insertLastBarang(LB, id, harga, nama);
            else
                cout << "Pilihan tidak valid\n";
        }

    } while (choice != 0);

    return 0;
}

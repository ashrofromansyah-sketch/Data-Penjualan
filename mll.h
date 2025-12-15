#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk barang (items) di list umum
struct Barang {
    string idBarang;
    string namaBarang;
    Barang* next;
};

// Struktur data untuk relasi antar toko dan barang
struct Relasi {
    Barang* barang; // pointer ke barang dalam list Barang
    Relasi* next;
};

// Struktur data untuk toko (stores) di list parent
struct Toko {
    string idToko;
    string namaToko;
    Toko* next;
    Relasi* firstRelasi; // pointer ke daftar relasi barang yang dijual toko ini
};

// ADT untuk list Barang (list tanpa relasi)
struct ListBarang {
    Barang* head;
    Barang* tail;
};

// ADT untuk list Toko (list parent dengan relasi ke barang)
struct ListToko {
    Toko* head;
    Toko* tail;
};

// Inisialisasi list toko
void createListToko(ListToko &LT) {
    LT.head = NULL;
    LT.tail = NULL;
}

// Inisialisasi list barang
void createListBarang(ListBarang &LB) {
    LB.head = NULL;
    LB.tail = NULL;
}

// Membuat dan menambahkan data toko di depan list
void insertFirstToko(ListToko &LT, string id, string nama) {
    Toko* newNode = new Toko;
    newNode->idToko = id;
    newNode->namaToko = nama;
    newNode->next = LT.head;
    newNode->firstRelasi = NULL;
    if (LT.head == NULL) {
        // Jika list masih kosong, tail juga menunjuk node baru
        LT.tail = newNode;
    }
    LT.head = newNode;
}

// Menambahkan data toko di belakang list
void insertLastToko(ListToko &LT, string id, string nama) {
    Toko* newNode = new Toko;
    newNode->idToko = id;
    newNode->namaToko = nama;
    newNode->next = NULL;
    newNode->firstRelasi = NULL;
    if (LT.head == NULL) {
        // List kosong, head dan tail menunjuk node baru
        LT.head = newNode;
        LT.tail = newNode;
    } else {
        // Tambahkan di ujung list dan perbarui tail
        LT.tail->next = newNode;
        LT.tail = newNode;
    }
}

// Menampilkan semua data toko (id dan nama)
void showAllToko(ListToko &LT) {
    cout << "Daftar Toko:\n";
    if (LT.head == NULL) {
        cout << "  (List toko kosong)\n";
    }
    Toko* p = LT.head;
    while (p != NULL) {
        cout << "  ID: " << p->idToko << ", Nama: " << p->namaToko << "\n";
        p = p->next;
    }
}

// Cari toko berdasarkan ID atau nama (mengembalikan pointer Toko atau NULL)
Toko* findToko(ListToko &LT, string key) {
    Toko* p = LT.head;
    while (p != NULL) {
        if (p->idToko == key || p->namaToko == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Hapus semua relasi pada toko (membebaskan node relasi)
void deleteAllRelasi(Toko* toko) {
    Relasi* r = toko->firstRelasi;
    while (r != NULL) {
        Relasi* toDelete = r;
        r = r->next;
        delete toDelete;
    }
    toko->firstRelasi = NULL;
}

// Menghapus toko dan semua relasinya dari list toko
void deleteToko(ListToko &LT, string id) {
    if (LT.head == NULL) return;
    Toko* cur = LT.head;
    Toko* prev = NULL;
    // Cari toko
    while (cur != NULL && cur->idToko != id) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Toko dengan ID " << id << " tidak ditemukan.\n";
        return;
    }
    // Lepas node toko dari list
    if (prev == NULL) {
        // Menghapus head
        LT.head = cur->next;
        if (LT.tail == cur) {
            // Jika hanya satu elemen, tail juga dihapus
            LT.tail = NULL;
        }
    } else {
        prev->next = cur->next;
        if (LT.tail == cur) {
            // Jika yang dihapus tail, update tail
            LT.tail = prev;
        }
    }
    // Hapus relasi barang dalam toko tersebut
    deleteAllRelasi(cur);
    // Hapus node toko
    delete cur;
    cout << "Toko dengan ID " << id << " telah dihapus beserta relasi barangnya.\n";
}

// Menambahkan data barang pada list barang (di belakang)
void insertLastBarang(ListBarang &LB, string id, string nama) {
    Barang* newNode = new Barang;
    newNode->idBarang = id;
    newNode->namaBarang = nama;
    newNode->next = NULL;
    if (LB.head == NULL) {
        // List kosong
        LB.head = newNode;
        LB.tail = newNode;
    } else {
        // Tambahkan di akhir
        LB.tail->next = newNode;
        LB.tail = newNode;
    }
}

// Cari barang pada list barang berdasarkan ID atau nama
Barang* findBarang(ListBarang &LB, string key) {
    Barang* p = LB.head;
    while (p != NULL) {
        if (p->idBarang == key || p->namaBarang == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Menambahkan relasi antara toko dan barang (toko menjual barang tertentu)
void addRelasi(Toko* toko, Barang* barang) {
    if (toko == NULL || barang == NULL) return;
    // Cek apakah relasi sudah ada
    Relasi* r = toko->firstRelasi;
    while (r != NULL) {
        if (r->barang == barang) {
            // Relasi sudah ada, tidak perlu menambahkan lagi
            return;
        }
        r = r->next;
    }
    // Buat node relasi baru
    Relasi* newRel = new Relasi;
    newRel->barang = barang;
    // Insert di depan list relasi toko
    newRel->next = toko->firstRelasi;
    toko->firstRelasi = newRel;
}

// Tampilkan semua toko beserta barang yang dijualnya
void showTokoAndBarang(ListToko &LT) {
    cout << "Semua Toko dan Barang yang dijual:\n";
    Toko* p = LT.head;
    while (p != NULL) {
        cout << "Toko ID " << p->idToko << " - " << p->namaToko << "\n";
        Relasi* r = p->firstRelasi;
        if (r == NULL) {
            cout << "  (Tidak ada barang terhubung)\n";
        }
        while (r != NULL) {
            cout << "  * " << r->barang->idBarang << " - " << r->barang->namaBarang << "\n";
            r = r->next;
        }
        p = p->next;
    }
}

// Cari barang tertentu dalam toko tertentu
void searchBarangInToko(Toko* toko, string key) {
    if (toko == NULL) {
        cout << "Toko tidak ditemukan.\n";
        return;
    }
    Relasi* r = toko->firstRelasi;
    while (r != NULL) {
        if (r->barang->idBarang == key || r->barang->namaBarang == key) {
            cout << "Barang ditemukan: ID " << r->barang->idBarang << ", Nama " << r->barang->namaBarang << "\n";
            return;
        }
        r = r->next;
    }
    cout << "Barang dengan ID/Nama \"" << key << "\" tidak ditemukan di toko ini.\n";
}

// Hapus barang dari toko tertentu (dengan menghapus node relasi)
void deleteBarangFromToko(Toko* toko, string idBarang) {
    if (toko == NULL) return;
    Relasi* r = toko->firstRelasi;
    Relasi* prev = NULL;
    while (r != NULL) {
        if (r->barang->idBarang == idBarang) {
            if (prev == NULL) {
                // Hapus first relasi
                toko->firstRelasi = r->next;
            } else {
                prev->next = r->next;
            }
            delete r;
            cout << "Relasi barang dengan ID " << idBarang << " pada toko dihapus.\n";
            return;
        }
        prev = r;
        r = r->next;
    }
    cout << "Barang dengan ID " << idBarang << " tidak ditemukan di toko ini.\n";
}

// Hitung jumlah barang dalam toko tertentu (jumlah node relasi)
int countBarangInToko(Toko* toko) {
    int count = 0;
    Relasi* r = toko->firstRelasi;
    while (r != NULL) {
        count++;
        r = r->next;
    }
    return count;
}

int main() {
    ListToko LT;
    ListBarang LB;
    createListToko(LT);
    createListBarang(LB);
    int choice;
    do {
        cout << "\n=== Menu Data Penjualan ===\n";
        cout << "1. Insert data toko (depan)\n";
        cout << "2. Tampilkan semua data toko\n";
        cout << "3. Hapus toko dan relasinya\n";
        cout << "4. Cari data toko (ID/Nama)\n";
        cout << "5. Insert data barang\n";
        cout << "6. Hubungkan toko ke barang (tambah relasi)\n";
        cout << "7. Tampilkan semua toko dan barangnya\n";
        cout << "8. Cari barang dalam toko\n";
        cout << "9. Hapus barang dari toko\n";
        cout << "10. Hitung jumlah barang dalam toko\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: "; cin >> choice;
        cin.ignore(); // buang newline
        if (choice == 0) {
            cout << "Keluar program.\n";
        } else if (choice == 1) {
            // Insert data toko (depan atau belakang)
            string id, nama;
            cout << "Masukkan ID toko: "; getline(cin, id);
            cout << "Masukkan nama toko: "; getline(cin, nama);
            cout << "Pilihan penempatan (1=depan, 2=belakang): ";
            int pos; cin >> pos;
            cin.ignore();
            if (pos == 1) {
                insertFirstToko(LT, id, nama);
            } else {
                insertLastToko(LT, id, nama);
            }
            cout << "Toko berhasil ditambahkan.\n";
        } else if (choice == 2) {
            // Tampilkan semua data toko
            showAllToko(LT);
        } else if (choice == 3) {
            // Hapus toko
            string id;
            cout << "Masukkan ID toko yang akan dihapus: "; getline(cin, id);
            deleteToko(LT, id);
        } else if (choice == 4) {
            // Cari toko
            string key;
            cout << "Masukkan ID/Nama toko: "; getline(cin, key);
            Toko* t = findToko(LT, key);
            if (t != NULL) {
                cout << "Toko ditemukan: ID " << t->idToko << ", Nama " << t->namaToko << "\n";
            } else {
                cout << "Toko tidak ditemukan.\n";
            }
        } else if (choice == 5) {
            // Insert data barang
            string id, nama;
            cout << "Masukkan ID barang: "; getline(cin, id);
            cout << "Masukkan nama barang: "; getline(cin, nama);
            insertLastBarang(LB, id, nama);
            cout << "Barang berhasil ditambahkan.\n";
        } else if (choice == 6) {
            // Hubungkan toko ke barang
            string idToko, idBarang;
            cout << "Masukkan ID toko: "; getline(cin, idToko);
            Toko* t = findToko(LT, idToko);
            if (t == NULL) {
                cout << "Toko tidak ditemukan.\n";
            } else {
                cout << "Masukkan ID barang: "; getline(cin, idBarang);
                Barang* b = findBarang(LB, idBarang);
                if (b == NULL) {
                    cout << "Barang tidak ditemukan. Pastikan sudah memasukkan data barang.\n";
                } else {
                    addRelasi(t, b);
                    cout << "Relasi toko-barang berhasil dibuat.\n";
                }
            }
        } else if (choice == 7) {
            // Tampilkan semua toko beserta barang
            showTokoAndBarang(LT);
        } else if (choice == 8) {
            // Cari barang dalam toko
            string idToko, idBarang;
            cout << "Masukkan ID toko: "; getline(cin, idToko);
            Toko* t = findToko(LT, idToko);
            if (t == NULL) {
                cout << "Toko tidak ditemukan.\n";
            } else {
                cout << "Masukkan ID/Nama barang yang dicari: "; getline(cin, idBarang);
                searchBarangInToko(t, idBarang);
            }
        } else if (choice == 9) {
            // Hapus barang dari toko
            string idToko, idBarang;
            cout << "Masukkan ID toko: "; getline(cin, idToko);
            Toko* t = findToko(LT, idToko);
            if (t == NULL) {
                cout << "Toko tidak ditemukan.\n";
            } else {
                cout << "Masukkan ID barang yang akan dihapus dari toko: "; getline(cin, idBarang);
                deleteBarangFromToko(t, idBarang);
            }
        } else if (choice == 10) {
            // Hitung jumlah barang dalam toko
            string idToko;
            cout << "Masukkan ID toko: "; getline(cin, idToko);
            Toko* t = findToko(LT, idToko);
            if (t == NULL) {
                cout << "Toko tidak ditemukan.\n";
            } else {
                int jumlah = countBarangInToko(t);
                cout << "Jumlah barang di toko " << t->idToko << ": " << jumlah << "\n";
            }
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

    return 0;
}

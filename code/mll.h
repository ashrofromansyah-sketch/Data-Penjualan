#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

/* ===== Struktur Data ===== */
struct Barang {
    string idBarang;
    string namaBarang;
    Barang* next;
};

struct Relasi {
    Barang* barang;
    Relasi* next;
};

struct Toko {
    string idToko;
    string namaToko;
    Toko* next;
    Relasi* firstRelasi;
};

struct ListBarang {
    Barang* head;
    Barang* tail;
};

struct ListToko {
    Toko* head;
    Toko* tail;
};

void createListToko(ListToko &LT);
void createListBarang(ListBarang &LB);

// Insert
void insertFirstToko(ListToko &LT, string id, string nama);
void insertLastToko(ListToko &LT, string id, string nama);
void insertLastBarang(ListBarang &LB, string id, string nama);

// Tampil
void showAllToko(ListToko &LT);
void showTokoAndBarang(ListToko &LT);

// Search
Toko* findToko(ListToko &LT, string key);
Barang* findBarang(ListBarang &LB, string key);
void searchBarangInToko(Toko* toko, string key);

// Relasi
void addRelasi(Toko* toko, Barang* barang);

// Delete
void deleteAllRelasi(Toko* toko);
void deleteToko(ListToko &LT, string id);
void deleteBarangFromToko(Toko* toko, string idBarang);

// Count
int countBarangInToko(Toko* toko);

#endif

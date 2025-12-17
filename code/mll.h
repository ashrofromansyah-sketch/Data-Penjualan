#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

//node
struct Barang {
    string idBarang;
    string namaBarang;
    int hargaBarang;
    Barang* next;
    struct Relasi* firstRelasiBarang;
};

struct Toko {
    string idToko;
    string namaToko;
    double ratingToko;
    Toko* next;
    struct Relasi* firstRelasiToko;
};

struct Relasi {
    Toko* toko;
    Barang* barang;
    Relasi* nextRelasiToko;
    Relasi* nextRelasiBarang;
};

//list
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
void insertFirstToko(ListToko &LT, string id, double rating, string nama);
void insertLastToko(ListToko &LT, string id, double rating, string nama);
void insertLastBarang(ListBarang &LB, string id, int harga, string nama);
void insertFirstBarang(ListBarang &LB, string id, int harga, string nama);

// Tampil
void showAllToko(ListToko &LT);
void showAllBarang(ListBarang &LB);
void showTokoAndBarang(ListToko &LT);
void tokoMenjualBarang(ListToko &LT, string idBarang);
void barangDijualToko(ListBarang &LB, string idToko);

// Search
Toko* findToko(ListToko &LT, string key);
Barang* findBarang(ListBarang &LB, string key);
Relasi* findRelasi(Toko* toko, Barang* barang);
void searchBarangInToko(Toko* toko, string key);

// Relasi
void addRelasi(Toko* toko, Barang* barang);

// Delete
void deleteRelasi(Toko* toko, Barang* barang);
void deleteToko(ListToko &LT, string id);
void deleteBarang(ListBarang &LB, string id);

// Count
int countBarangInToko(Toko* toko);

#endif

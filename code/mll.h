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

struct Relasi {
    Toko* toko;
    Barang* barang;
    Relasi* nextRelasiToko;
    Relasi* nextRelasiBarang;
};

struct Toko {
    string idToko;
    string namaToko;
    double ratingToko;
    Toko* next;
    struct Relasi* firstRelasiToko;
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
void insertFirstToko(ListToko &LT, string id, string nama);
void insertLastToko(ListToko &LT, string id, string nama);
void insertLastBarang(ListBarang &LB, string id, string nama);
void insertFirstBarang(ListBarang &LB, string id, string nama);

// Tampil
void showAllToko(ListToko &LT);
void showAllBarang(ListBarang &LB);
void showTokoAndBarang(ListToko &LT);

// Search
Toko* findToko(ListToko &LT, string key);
Barang* findBarang(ListBarang &LB, string key);
//cari realasi child dari toko atau barang
void searchBarangInToko(Toko* toko, string key);

//toko yang menjual barang tertentu
void tokoMenjualBarang(ListToko &LT, string idBarang);

// Relasi
void addRelasi(Toko* toko, Barang* barang);

// Delete
void deleteRelasi(Toko* toko);
void deleteToko(ListToko &LT, string id);
void deleteBarang(ListBarang &LB, string id);
void deleteBarangFromToko(Toko* toko, string idBarang);

// Count
int countBarangInToko(Toko* toko);

#endif

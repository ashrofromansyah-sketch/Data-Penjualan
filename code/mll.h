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

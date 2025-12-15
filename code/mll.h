#ifndef MLL_H
#define MLL_H

#include <string>
using namespace std;

//node toko
struct Toko {
    int id;
    string nama;
    Toko *next;
};
//node barang
struct Barang {
    int id;
    string nama;
    string kategori; //misal: makanan, minuman, pembersih, perabot, dll
    double harga;
    Barang *next;
};

struct Relasi {
    Toko *toko;
    Barang *barang;
    Relasi *next;
};

struct ListToko {
    Toko *first;
};

struct ListBarang {
    Barang *first;
};

struct ListRelasi {
    Relasi *first;
};
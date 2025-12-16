#include "mll.h"

/* ===== Inisialisasi ===== */
void createListToko(ListToko &LT) {
    LT.head = NULL;
    LT.tail = NULL;
}

void createListBarang(ListBarang &LB) {
    LB.head = NULL;
    LB.tail = NULL;
}

/* ===== Insert Toko ===== */
void insertFirstToko(ListToko &LT, string id, string nama) {
    Toko* newNode = new Toko;
    newNode->idToko = id;
    newNode->namaToko = nama;
    newNode->firstRelasi = NULL;
    newNode->next = LT.head;

    if (LT.head == NULL)
        LT.tail = newNode;

    LT.head = newNode;
}

void insertLastToko(ListToko &LT, string id, string nama) {
    Toko* newNode = new Toko;
    newNode->idToko = id;
    newNode->namaToko = nama;
    newNode->firstRelasi = NULL;
    newNode->next = NULL;

    if (LT.head == NULL) {
        LT.head = newNode;
        LT.tail = newNode;
    } else {
        LT.tail->next = newNode;
        LT.tail = newNode;
    }
}

/* ===== Insert Barang ===== */
void insertLastBarang(ListBarang &LB, string id, string nama) {
    Barang* newNode = new Barang;
    newNode->idBarang = id;
    newNode->namaBarang = nama;
    newNode->next = NULL;

    if (LB.head == NULL) {
        LB.head = newNode;
        LB.tail = newNode;
    } else {
        LB.tail->next = newNode;
        LB.tail = newNode;
    }
}

/* ===== Tampil ===== */
void showAllToko(ListToko &LT) {
    Toko* p = LT.head;
    if (p == NULL) {
        cout << "List toko kosong\n";
        return;
    }

    while (p != NULL) {
        cout << "ID: " << p->idToko << " | Nama: " << p->namaToko << endl;
        p = p->next;
    }
}

void showTokoAndBarang(ListToko &LT) {
    Toko* t = LT.head;
    while (t != NULL) {
        cout << "\nToko: " << t->idToko << " - " << t->namaToko << endl;
        Relasi* r = t->firstRelasi;
        if (r == NULL)
            cout << "  (Tidak ada barang)\n";
        while (r != NULL) {
            cout << "  * " << r->barang->idBarang
                 << " - " << r->barang->namaBarang << endl;
            r = r->next;
        }
        t = t->next;
    }
}

/* ===== Search ===== */
Toko* findToko(ListToko &LT, string key) {
    Toko* p = LT.head;
    while (p != NULL) {
        if (p->idToko == key || p->namaToko == key)
            return p;
        p = p->next;
    }
    return NULL;
}

Barang* findBarang(ListBarang &LB, string key) {
    Barang* p = LB.head;
    while (p != NULL) {
        if (p->idBarang == key || p->namaBarang == key)
            return p;
        p = p->next;
    }
    return NULL;
}

/* ===== Relasi ===== */
void addRelasi(Toko* toko, Barang* barang) {
    Relasi* r = toko->firstRelasi;
    while (r != NULL) {
        if (r->barang == barang)
            return;
        r = r->next;
    }

    Relasi* newRel = new Relasi;
    newRel->barang = barang;
    newRel->next = toko->firstRelasi;
    toko->firstRelasi = newRel;
}

/* ===== Delete ===== */
void deleteAllRelasi(Toko* toko) {
    Relasi* r = toko->firstRelasi;
    while (r != NULL) {
        Relasi* del = r;
        r = r->next;
        delete del;
    }
    toko->firstRelasi = NULL;
}

void deleteToko(ListToko &LT, string id) {
    Toko* cur = LT.head;
    Toko* prev = NULL;

    while (cur != NULL && cur->idToko != id) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Toko tidak ditemukan\n";
        return;
    }


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

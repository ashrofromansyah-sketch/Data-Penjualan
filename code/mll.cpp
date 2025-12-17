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
    newNode->firstRelasiToko = NULL;
    newNode->next = LT.head;

    if (LT.head == NULL)
        LT.tail = newNode;

    LT.head = newNode;
}

void insertLastToko(ListToko &LT, string id, string nama) {
    Toko* newNode = new Toko;
    newNode->idToko = id;
    newNode->namaToko = nama;
    newNode->ratingToko = 0.0;
    newNode->firstRelasiToko = NULL;
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
    newNode->hargaBarang = 0;
    newNode->firstRelasiBarang = NULL;
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
        Relasi* r = t->firstRelasiToko;
        if (r == NULL)
            cout << "  (Tidak ada barang)\n";
        while (r != NULL) {
            cout << "  * " << r->barang->idBarang
                 << " - " << r->barang->namaBarang << endl;
            r = r->nextRelasiToko;
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

Relasi* findRelasi(Toko* toko, Barang* barang) {
    Relasi* r = toko->firstRelasiToko;
    while (r != NULL) {
        if (r->barang == barang)
            return r;
        r = r->nextRelasiToko;
    }
    return NULL;
}

/* ===== Relasi ===== */
void addRelasi(Toko* toko, Barang* barang) {
    if (toko == NULL || barang == NULL) return;
    if (findRelasi(toko, barang) != NULL) return;

    Relasi* r = new Relasi;
    r->toko = toko;
    r->barang = barang;

    r->nextRelasiToko = toko->firstRelasiToko;
    toko->firstRelasiToko = r;

    r->nextRelasiBarang = barang->firstRelasiBarang;
    barang->firstRelasiBarang = r;
}

/* ===== Delete ===== */
void deleteRelasi(Toko* toko, Barang* barang) {
    if (toko == NULL || barang == NULL) return;

    Relasi *r, *prev;

    r = toko->firstRelasiToko;
    prev = NULL;
    while (r != NULL && r->barang != barang) {
        prev = r;
        r = r->nextRelasiToko;
    }
    if (r == NULL) return;

    if (prev == NULL)
        toko->firstRelasiToko = r->nextRelasiToko;
    else
        prev->nextRelasiToko = r->nextRelasiToko;

    prev = NULL;
    Relasi* rb = barang->firstRelasiBarang;
    while (rb != NULL && rb != r) {
        prev = rb;
        rb = rb->nextRelasiBarang;
    }

    if (prev == NULL)
        barang->firstRelasiBarang = rb->nextRelasiBarang;
    else
        prev->nextRelasiBarang = rb->nextRelasiBarang;

    delete r;
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

    while (cur->firstRelasiToko != NULL) {
        deleteRelasi(cur, cur->firstRelasiToko->barang);
    }

    if (prev == NULL)
        LT.head = cur->next;
    else
        prev->next = cur->next;

    if (LT.tail == cur)
        LT.tail = prev;

    delete cur;
}

void deleteBarangFromToko(Toko* toko, string idBarang) {
    Relasi* r = toko->firstRelasiToko;
    Relasi* prev = NULL;

    while (r != NULL) {
        if (r->barang->idBarang == idBarang) {
            if (prev == NULL)
                toko->firstRelasiToko = r->nextRelasiToko;
            else
                prev->nextRelasiToko = r->nextRelasiToko;

            delete r;
            return;
        }
        prev = r;
        r = r->nextRelasiToko;
    }
}

/* ===== Count ===== */
int countBarangInToko(Toko* toko) {
    int count = 0;
    Relasi* r = toko->firstRelasiToko;
    while (r != NULL) {
        count++;
        r = r->nextRelasiToko;
    }
    return count;
}


# Data-Penjualan
 Program Data Penjualan ini merupakan implementasi Multi Linked List (MLL)
menggunakan bahasa C++ untuk memodelkan hubungan antara Toko dan Barang.

##  Tujuan
- Menerapkan konsep Multi Linked List
- Melatih penggunaan pointer dan linked list
- Mengelola data penjualan antara toko dan barang

---

##  Konsep Struktur Data
Program ini menggunakan konsep **Multi Linked List**, dengan penjelasan sebagai berikut:
- **Toko** berperan sebagai **parent node**
- **Barang** berperan sebagai **parent node**
- **Relasi** berperan sebagai **child node** yang menghubungkan antara Toko dan Barang

Setiap toko dapat memiliki lebih dari satu relasi barang, dan setiap barang dapat
dihubungkan ke lebih dari satu toko melalui node relasi.

---

##  Struktur File
Program ini terdiri dari tiga file utama:
- `mll.h` : Berisi deklarasi struktur data dan prototype fungsi
- `mll.cpp` : Berisi implementasi fungsi-fungsi Multi Linked List
- `main.cpp` : Berisi program utama dan menu interaktif

---

##  Fitur Program
Fitur-fitur yang tersedia dalam program ini meliputi:
- Menambahkan data toko
- Menampilkan data toko
- Menambahkan data barang
- Menghubungkan toko dengan barang (data penjualan)
- Menampilkan toko beserta barang yang dijual
- Menghitung jumlah barang yang dimiliki oleh suatu toko

---

##  Cara Menjalankan Program
Langkah-langkah menjalankan program menggunakan **Visual Studio Code**:

1. Pastikan compiler **g++** telah terinstal
2. Buka folder project di **Visual Studio Code**
3. Buka terminal pada VS Code (`Ctrl + ~`)
4. Jalankan perintah berikut:
   ```bash
   g++ main.cpp mll.cpp -o penjualan

---

## ketentuan tugas
i. Aturan struktur data :
1. Menggunakan dua jenis list yang berbeda sesuai plotingan dari Dosen Kelas. //pilih m-n
2. Insert dan delete elemen list yang digunakan harus memiliki insert first dan insert
last/delete first dan delete last, tidak boleh seragam di dua list yang ada. //pilih insert first dan last
3. Data yang disimpan pada kedua list parent harus berupa tipe bentukan dan
minimal memiliki 3 data dimana minimal salah satu data bertipe integer atau real // ada rating toko dan harga barang
4. Data pada element child minimal berupa pointer, boleh menambahkan data
lainnya jika dirasa perlu // hanya pointer

ii. Desain struktur data :
1. 1 Buah list dengan list relasi
2. 1 Buah list tanpa list relasi

iii. Fungsionalitas (Total poin 100 Poin dan diambil 100% untuk nilai kelompok) :
1. Insert data parent dari depan/belakang //insertFirstToko, insertLastToko, insertFirstBarang, insertLastBarang
2. Show all data parent //showAllToko n showAllBarang
3. Menghapus data parent beserta relasinya // deleteToko n deleteBarang
4. Mencari data parent //findToko n findBarang
5. Mencari data child // findRelasi
6. Menambahkan data child // addRelasi
7. Menghubungkan data parent ke data child // addRelasi
8. Menampilkan seluruh data parent beserta childnya// showTokoAndBarang
9. Mencari data child pada parent tertentu //findRelasi
10. Menghapus data child pada parent tertentu beserta relasinya // deleteRelasi
11. Menghitung jumlah data child dari parent tertentu //countBarangInToko
12. Main program

Judul : Data Penjualan 
Descripsi : implementasikan multi linked-list yang memodelkan data toko dan data barang beserta relasi keduanya. 
Suatu toko bisa menjual banyak barang. Dan suatu barang bisa di jual oleh banyak toko. Fungsionalitas : 
a. Penambahan data toko // insertFirstToko, insertLastToko
b. Penambahan data barang // insertFirstBarang, insertLastBarang 
c. Penentuan relasi toko dan barang yang dijual (dan sebalikknya) // 
d. Menghapus data toko // deleteToko
e. Manghapus data barang // deleteBarang
f. Menampilkan data keseluruhan toko beserta data barang yang dijualnya // showTokoAndBarang
g. Menampilkan data barang yang dijual oleh toko tertentu // barangDijualToko
h. Menampilkan data toko menjual barang tertentu // tokoMenjualBarang
i. Menampilkan data toko yang paling lengkap jualannya dan yang paling sedikit // countBarangInToko 

gambaran:
   ```bash
      Data Penjualan
      |
      ├── Toko A
      │   ├── Relasi ke Beras
      │   ├── Relasi ke Minyak Goreng
      │   └── Relasi ke Gula Pasir
      |
      ├── Toko B
      │   ├── Relasi ke Gula Pasir
      │   ├── Relasi ke Susu Bubuk
      │   └── Relasi ke Kopi Hitam
      |
      └── Toko C
         ├── Relasi ke Beras
         ├── Relasi ke Tepung Terigu
         └── Relasi ke Kopi Hitam
   ---

Program Data Penjualan ini diharapkan dapat membantu dalam memahami penerapan
struktur data Multi Linked List pada kasus nyata, khususnya dalam pengelolaan
data penjualan antara toko dan barang. Program ini masih dapat dikembangkan lebih
lanjut sesuai kebutuhan.

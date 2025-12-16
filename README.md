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

Program Data Penjualan ini diharapkan dapat membantu dalam memahami penerapan
struktur data Multi Linked List pada kasus nyata, khususnya dalam pengelolaan
data penjualan antara toko dan barang. Program ini masih dapat dikembangkan lebih
lanjut sesuai kebutuhan.

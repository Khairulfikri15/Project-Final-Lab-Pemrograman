Anggota kelompok 3:
1. fitriani_2408107010022
2. ⁠Fawwaz_Ziyadi_Ilmi_2408107010021
3. ⁠Muhammad_Riyadh_2408107010015
4. Aulia_Lutfi_2408107010033
5. Khairul_Fikri_2408107010032
6. abdi_dzil_ikram_2408107010024

PROJECT PEMINJAMAN ALAT LABORATORIUM
Proyek ini bertujuan untuk membuat sebuah sistem peminjaman alat laboratorium menggunakan bahasa pemrograman C. Sistem akan dirancang berbasis Command Line Interface (CLI), di mana pengguna dapat berinteraksi melalui terminal atau command prompt. Sistem ini mendukung pengelolaan alat laboratorium secara digital, melibatkan pengguna dengan dua jenis akun: Admin dan User, yang masing-masing memiliki hak akses dan fitur berbeda.
Tujuan Sistem
1.	Efisiensi Pengelolaan Alat Laboratorium:
Sistem ini membantu laboratorium untuk mengelola alat-alat yang dipinjam dan dikembalikan secara terstruktur.
2.	Manajemen Data yang Terpusat:
Semua data disimpan dalam file berformat .txt, memastikan data dapat diakses kembali meskipun program dimatikan.
3.	Otomasi Proses Manual:
Menggantikan pencatatan manual dengan proses otomatis yang melibatkan login, pengelolaan alat, dan pencatatan peminjaman.

Alur Penggunaan Aplikasi
1.	Login:
o	Pengguna memasukkan username dan password melalui CLA.
o	Sistem memverifikasi data terhadap file akun.txt.
2.	Fitur Admin:
o	Admin dapat menambah, menghapus, atau mengedit data alat laboratorium.
3.	Fitur User:
o	User dapat melihat daftar alat yang tersedia.
o	User meminjam alat tertentu, yang kemudian dicatat di file listPinjam.txt.
o	User mengembalikan alat, dan sistem menghapus catatan dari listPinjam.txt serta mengembalikan jumlah alat di file listTersedia.txt.
4.	Keluar dari Sistem:
o	Setelah semua aktivitas selesai, pengguna dapat keluar dari sistem.

FUNGSI-FUNGSINYA
return.c : sebuah fungsi pengembalian dimana fungsi ini akan menghapus data di file listPinjam.txt dengan cara menulis semua data kecuali data yang mau dikembalikan ke file term.txt, kemudian file tersebut di rename menjadi file listTersedia.txt.

PinjamAlat.c : sebuah fungsi peminjaman yang menambahkan data ke file listTersimpan.txt dengan menggunakan fungsi fprintf, sebelum ditambahkan di cek terlebih dahulu ke file listTersedia.txt, kalau datanya ada baru peminjaman boleh dilakukan.

LihatList.c : sebuah fungsi untuk membaca data dari file listTersedia.txt kemudian menampilkannya ke layar/terminal

Lihatpinjam.c : sebuah fungsi untuk membaca data dari file listpinjam.txt kemudian menampilkannya ke layar/terminal

Tambahdata.c: sebuah fungsi penambahan data ke file listTersedia.txt dengan menggunakan fungsi fprintf untuk mencetak datanya ke file listTersedia.txt setelah sebelumnya data diinput dengan menggunakan fungsi scanf. Fungsi ini dibuat hanya untuk admin.

EditData.c: sebuah fungsi pengeditan data ke file listTersedia.txt berdasarkan id alat yang di input oleh admin. Fungsi ini dibuat hanya untuk admin.

HapusData.c: sebuah fungsi penghapusan data yang ada di file listTersedia.txt berdasarkan id alat yang di input oleh admin. Fungsi ini dibuat hanya untuk admin.

ListTersedia.txt : Sebuah file yang berisi data data alat laboratorium yang disimpan dengan format teratur. Data di file ini digunakan oleh fungsi fungsi yang telah dibuat untuk program ini.

ListPinjam.txt: Sebuah file yang berisi data alat laboratorium yang telah dipinjam oleh pengguna. File ini merupakan output dari fungsi pinjamAlat.

Akun.txt: Sebuah file yang berisi data username dan password akun pengguna. Data ini digunakan dalam fungsi login untuk masuk ke dalam program dan menentukan apakah akun tersebut adalah user atau admin.

Header.h: Sebuah file header yang berisi prototype dari fungsi fungsi yang telah dibuat untuk nantinya di panggil kembali di program main.c

Login.c : Fungsi menuLogin adalah sebuah program untuk memverifikasi login pengguna dengan membaca data dari file bernama "akun.txt".

MAKE FILE
Makefile ini membantu mengelola proyek dengan banyak file sumber secara otomatis, sehingga mempermudah pengembang untuk kompilasi ulang hanya pada bagian yang berubah.
Makefile ini digunakan untuk mengompilasi program dengan efisien menggunakan gcc. Berikut adalah komponennya:
 
1. Variabel:
CC = gcc: Menentukan compiler yang digunakan (gcc).
CFLAGS = -Wall -g: Opsi kompilasi:
-Wall: Mengaktifkan semua peringatan.
-g: Menyertakan informasi debugging.
OBJ: Daftar file object (.o) yang dihasilkan dari file .c.
2. Target Utama:
all: lab: Target utama. Memanggil target lab untuk menghasilkan file eksekusi lab.
lab: $(OBJ): Menghubungkan semua file object ($(OBJ)) untuk membentuk file eksekusi lab:
gcc -Wall -g -o lab main.o login.o ...
3. Target Kompilasi File .c:
Setiap file .c dikompilasi menjadi file .o dengan perintah:
gcc -Wall -g -c [nama_file].c
Contoh:
main.o: main.c header.h
​$(CC) $(CFLAGS) -c main.c
4. Target clean:
Membersihkan file hasil kompilasi menggunakan perintah:
rm -f *.o lab

SOAL BONUS
Soal bonus ini merupakan program yang bertujuan untuk membaca lirik lagu dari file teks, membersihkan kata-kata dari tanda baca, dan menyimpan kata-kata unik ke dalam file output.Program ini berguna untuk mengumpulkan dan menyimpan kata-kata unik dari lirik lagu, yang dapat digunakan untuk analisis lebih lanjut, seperti pembuatan kamus atau analisis frekuensi kata.

Header dan Definisi:

Kode ini mengimpor beberapa pustaka standar (stdio.h, stdlib.h, string.h, ctype.h) dan mendefinisikan beberapa konstanta untuk panjang maksimum baris, panjang maksimum kata, dan jumlah maksimum kata.
Fungsi clean:

Fungsi ini menerima sebuah string (kata) dan menghapus tanda baca, serta mengubah semua huruf menjadi huruf kecil. Hanya karakter alfanumerik, tanda hubung (-), dan apostrof (') yang diperbolehkan. Hasilnya disalin kembali ke string asli.
Fungsi main:

Membuka file input (lirik.txt) untuk dibaca dan file output (kosa-kata.word) untuk ditulis. Jika salah satu file gagal dibuka, program akan mencetak pesan kesalahan dan keluar.
Membaca baris pertama dari file input (yang diasumsikan sebagai judul) dan menuliskannya ke file output.
Membaca setiap baris lirik dari file input, memecahnya menjadi kata-kata menggunakan strtok, dan membersihkan setiap kata dengan memanggil fungsi clean.
Memeriksa apakah kata yang telah dibersihkan sudah ada dalam daftar kata yang telah disimpan. Jika tidak ada, kata tersebut disalin ke dalam array kata menggunakan strdup, dan ditulis ke file output dengan format kata=.
Menutup File dan Membebaskan Memori:

Setelah semua baris dibaca, file input dan output ditutup.
Memori yang dialokasikan untuk setiap kata dibebaskan untuk mencegah kebocoran memori.

#include <stdio.h>
#include "header.h"

int main () {

    //variabels
    
    int admin = 0;
    int option = 0;
    
    
    printf("========================================\n");
    printf("SELAMAT DATANG DI LABORATORIUM USK\n");
    printf("========================================\n");
    printf("\n");

    printf("Silahkan login terlebih dahulu\n");
    if(menuLogin(&admin)) {
        printf("Login berhasil\n");
        if(admin){
            printf("Anda login sebagai Admin\n");
        }else {
            printf("Anda login sebagai user\n");
        }
        
    }else{
        printf("Username dan password salah\n");
        return 1;
    }

    printf("\n");
    printf("Silahkan pilih menu di bawah\n");
    printf("1. Lihat alat Lab yang tersedia\n");
    printf("2. Peminjaman alat Lab\n");
    printf("3. Lihat list alat lab yang dipinjam\n");
    printf("4. Kembalikan alat lab yang dipinjam\n");

    if(admin){
        printf("5. Tambah data alat Lab\n");
        printf("6. Edit data alat Lab\n");
        printf("7. Hapus data alat Lab\n");
    }

    printf("option: ");
    scanf("%d", &option);

   switch (option)
   {
    case 1:
    if (lihatList()){
        printf("Lihat alat lab yang tersedia sudah berhasil\n");
    };
    break;

     case 2:
    if (pinjamAlat()){
        printf("Peminjaman alat sudah berhasil dilakukan\n");
    };
    break;

    case 3:
    if (lihatPinjam()){
        printf("Lihat alat lab yang sedang dipinjam sudah berhasil\n");
    };
    break;

    case 4: 
    if (pengembalian()){
        printf("Pengembalian alat lab sudah berhasil dilakukan\n");
    };
    break;

    case 5: 
    if  (admin) {
        if (tambahData()){
        printf("Penambahan alat lab sudah berhasil dilakukan\n");
        }
    } else{
        printf("Hanya admin yang boleh melakukan tambah Data\n");
        return 1;
    };
    break;

    case 6: 
    if (admin){
        if (editData()){
        printf("Edit data alat lab sudah berhasil dilakukan\n");
        }
    }else{
        printf("Hanya admin yang boleh melakukan edit Data\n");
        return 1;
    }; 
    break;

    case 7: 
    if (admin){
        if (hapusData()){
        printf("Hapus data alat lab sudah berhasil dilakukan\n");
        }
    }else{
        printf("Hanya admin yang boleh melakukan hapus Data\n");
        return 1;
    };
    break;

    default:
    printf("Option yang dipilih belum tersedia\n");
   }

 return 0;

}


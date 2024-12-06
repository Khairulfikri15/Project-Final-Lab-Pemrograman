#include "header.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int data_ID;
    char data_nama[100];
    char data_merek[100];
    char data_model[100];
    unsigned int data_tahun;
    unsigned int data_jumlah;
    unsigned int data_jml_tersedia;
} dataLab;

int pengembalian() {
    unsigned int ID;
    dataLab entry[100]; // Array untuk menyimpan data struct
    int count = 0;

    FILE *filePinjam;
    FILE *fileTemp;

    printf("Masukkan ID alat yang mau dikembalikan: ");
    scanf("%u", &ID);

    // Membuka file
    filePinjam = fopen("listPinjam.txt", "r");
    fileTemp = fopen("temp.txt", "w");

    if (filePinjam == NULL || fileTemp == NULL) {
        printf("Error: tidak dapat membuka file.\n");
        return 0;
    }

    // Membaca data dari file listPinjam.txt
   while (fscanf(filePinjam, "%u %s %s %s %u %u %u",
                  &entry[count].data_ID,
                  entry[count].data_nama,
                  entry[count].data_merek,
                  entry[count].data_model,
                  &entry[count].data_tahun,
                  &entry[count].data_jumlah,
                  &entry[count].data_jml_tersedia) != EOF) {
        count++;
    }

    // Menyalin data ke temp.txt kecuali data dengan ID yang ingin dihapus
  
    for (int i = 0; i < count; i++) {
        if (entry[i].data_ID != ID) {
            fprintf(fileTemp, "%u %s %s %s %u %u %u\n",
            entry[i].data_ID,
            entry[i].data_nama,
            entry[i].data_merek,
            entry[i].data_model,
            entry[i].data_tahun,
            entry[i].data_jumlah,
            entry[i].data_jml_tersedia + 1);
        } 
    }

    // Menutup file
    fclose(filePinjam);
    fclose(fileTemp);

    // Menghapus file asli dan mengganti nama file temp menjadi listPinjam.txt
    if (remove("listPinjam.txt") != 0 || rename("temp.txt", "listPinjam.txt") != 0) {
        printf("Error: tidak dapat memperbarui file.\n");
        return 0;
    }

    printf("Alat dengan ID %u berhasil dikembalikan.\n", ID);
    return 1;
}

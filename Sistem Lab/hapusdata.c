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

int hapusData() {
    unsigned int ID;
    dataLab entry[100]; // Array untuk menyimpan data struct
    int count = 0;

    FILE *fileData;
    FILE *fileTemp;

    printf("Masukkan ID alat yang mau dihapus: ");
    scanf("%u", &ID);

    // Membuka file
    fileData = fopen("listTersedia.txt", "r");
    fileTemp = fopen("temp.txt", "w");

    if (fileData == NULL || fileTemp == NULL) {
        printf("Error: tidak dapat membuka file.\n");
        return 0;
    }

    // Membaca data dari file listTersedia.txt
   while (fscanf(fileData, "%u %s %s %s %u %u %u",
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
            entry[i].data_jml_tersedia );
        } 
    }

    // Menutup file
    fclose(fileData);
    fclose(fileTemp);

    // Menghapus file asli dan mengganti nama file temp menjadi listTersedia.txt
    if (remove("listTersedia.txt") != 0 || rename("temp.txt", "listTersedia.txt") != 0) {
        printf("Error: tidak dapat memperbarui file.\n");
        return 0;
    }

    printf("Alat dengan ID %u berhasil dihapus.\n", ID);
    return 1;
}

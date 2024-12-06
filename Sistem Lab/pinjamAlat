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

int pinjamAlat() {
    dataLab entry[100]; // Array untuk menyimpan data struct
    int count = 0;
    unsigned int ID;

    FILE *fileData;
    FILE *file;

    // Membuka file
    file = fopen("listPinjam.txt", "a");
    fileData = fopen("listTersedia.txt", "r");
    if (file == NULL || fileData == NULL) {
        printf("Error: tidak dapat membuka file.\n");
        return 0;
    }
    
    // Memasukkan ID alat yang mau dipinjam
    printf("Masukkan ID alat yang mau dipinjam: ");
    scanf("%u", &ID);

    // Membaca data dari listTersedia.txt
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
   
    fclose(fileData);

    // Mencari alat dengan ID yang sesuai
    for (int i = 0; i < count; i++) {
        if (ID == entry[i].data_ID) {
            if (entry[i].data_jml_tersedia > 0) {
                printf("Data alat lab yang ingin dipinjam tersedia.\n");
               

                // Menulis data ke listPinjam.txt
                fprintf(file, "\n");
                fprintf(file, "%u ", entry[i].data_ID);
                fprintf(file, "%s ", entry[i].data_nama);
                fprintf(file, "%s ", entry[i].data_merek);
                fprintf(file, "%s ", entry[i].data_model);
                fprintf(file, "%u ", entry[i].data_tahun);
                fprintf(file, "%u ", entry[i].data_jumlah);
                fprintf(file, "%u ", entry[i].data_jml_tersedia - 1);
                fprintf(file, "\n");

                printf("Alat berhasil dipinjam.\n");
            } else {
                printf("Maaf, alat ini tidak tersedia untuk dipinjam.\n");
            }
            break;
        }
    }

    fclose(file);
    return 1;
}

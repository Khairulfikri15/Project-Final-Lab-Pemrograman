#include <stdio.h>
#include "header.h"

typedef struct {
    unsigned int data_ID;
    char data_nama[100];
    char data_merek[100];
    char data_model[100];
    unsigned int data_tahun;
    unsigned int data_jumlah;
    unsigned int data_jml_tersedia;
} dataLab;

int tambahData() {
    dataLab entry[100]; // Array untuk menyimpan data struct
    int i = 0;

    FILE *file;

    file = fopen("listTersedia.txt", "a");
    if (file == NULL){
        printf("Error: tidak dapat membuka file.\n");
        return 0;
    }


    printf("Masukkan ID alat: ");
    scanf("%u", &entry[i].data_ID);
    printf("Masukkan nama alat: ");
    scanf(" %s", entry[i].data_nama);
    printf("Masukkan merek alat: ");
    scanf(" %s", entry[i].data_merek);
    printf("Masukkan model alat: ");
    scanf(" %s", entry[i].data_model);
    printf("Masukkan tahun produksi: ");
    scanf("%u", &entry[i].data_tahun);
    printf("Masukkan jumlah unit: ");
    scanf("%u", &entry[i].data_jumlah);
    printf("Masukkan jumlah unit tersedia: ");
    scanf("%u", &entry[i].data_jml_tersedia);

    fprintf(file, "\n%u %s %s %s %u %u %u",
            entry[i].data_ID,
            entry[i].data_nama,
            entry[i].data_merek,
            entry[i].data_model,
            entry[i].data_tahun,
            entry[i].data_jumlah,
            entry[i].data_jml_tersedia);
            
        printf("\n");
    
    fclose(file);
    printf("Data berhasil ditambahkan ke file %s!\n", "listTersedia.txt");

    return 1;

}

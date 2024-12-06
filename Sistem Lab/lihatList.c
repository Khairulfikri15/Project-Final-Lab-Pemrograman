#include "header.h"
#include <stdio.h>
#include <string.h>

typedef struct 
{
    /* data */
    unsigned int data_ID;
    char data_nama[100];
    char data_merek[100];
    char data_model[100];
    unsigned int data_tahun;
    unsigned int data_jumlah;
    unsigned int data_jml_tersedia;
} dataLab;



int lihatList(){
  
    dataLab entry[100]; //array untuk menyimpan data struct
    int count = 0;

    FILE *file;
  
    //membuka file lihatList.txt
    file = fopen("listTersedia.txt", "r");
    if (file == NULL){
        printf("Error: tidak dapat membuka file.\n");
        return 0;
    }

    printf("Data alat lab yang tersedia\n");

    while (fscanf(file, "%u %s %s %s %u %u %u",
                  &entry[count].data_ID,
                  entry[count].data_nama,
                  entry[count].data_merek,
                  entry[count].data_model,
                  &entry[count].data_tahun,
                  &entry[count].data_jumlah,
                  &entry[count].data_jml_tersedia) != EOF) {
        count++;
    }
    fclose(file);


    for (int i = 0; i < count; i++)
    {
        /* code */
        printf("ID : %u\n", entry[i].data_ID);
        printf("Nama alat : %s\n", entry[i].data_nama);
        printf("Merek : %s\n", entry[i].data_merek);
        printf("Model : %s\n", entry[i].data_model);
        printf("Tahun produksi : %u\n", entry[i].data_tahun);
        printf("Jumlah unit : %u\n", entry[i].data_jumlah);
        printf("Jumlah unit tersedia : %u\n", entry[i].data_jml_tersedia);
        printf("\n");
    }
    return 1;

    
    

}

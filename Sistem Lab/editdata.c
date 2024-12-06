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

int editData() {
    char new_nama[100];
    char new_merek[100];
    char new_model[100];
    unsigned int new_tahun;
    unsigned int new_jumlah;
    unsigned int new_jml_tersedia;

    int pilih;
    int dataFound = 0;
    unsigned int ID;
    dataLab entry[100]; // Array untuk menyimpan data struct
    int count = 0;

    FILE *fileData;
    FILE *fileTemp;

    printf("Masukkan ID alat yang mau diedit: ");
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
        } else{
            dataFound = 1;
            printf("1. Nama alat\n");
            printf("2. Merek alat\n");
            printf("3. Model alat\n");
            printf("4. Tahun\n");
            printf("5. Jumlah alat\n");
            printf("6. Jumlah data tersedia\n");
            printf("Pilih data yang mau diedit: ");
            scanf("%d", &pilih);

            switch (pilih)
            {
                case 1:
                printf("Ubah nama alat: ");
                scanf("%s", new_nama);
                strcpy(entry[i].data_nama, new_nama);
                break;

                case 2:
                printf("Ubah merek alat: ");
                scanf("%s", new_merek);
                strcpy(entry[i].data_merek, new_merek);
                break;

                case 3:
                printf("Ubah model alat: ");
                scanf("%s", new_model);
                strcpy(entry[i].data_model, new_model);
                break;

                case 4:
                printf("Ubah tahun: ");
                scanf("%u", &new_tahun);
                entry[i].data_tahun = new_tahun;
                break;

                case 5:
                printf("Ubah jumlah alat: ");
                scanf("%u", &new_jumlah);
                entry[i].data_jumlah = new_jumlah;
                break;

                case 6:
                printf("Ubah jumlah tersedia: ");
                scanf("%u", &new_jml_tersedia);
                entry[i].data_jml_tersedia = new_jml_tersedia;
                break;

                default:
                printf("Option yang dipilih belum tersedia\n");
                return 0;
            }

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

    if(!dataFound){
        remove("temp.txt");
        printf("Alat dengan ID %u tidak tersedia.\n", ID);
        return 0;
    }

    // Menghapus file asli dan mengganti nama file temp menjadi listTersedia.txt
    if (remove("listTersedia.txt") != 0 || rename("temp.txt", "listTersedia.txt") != 0) {
        printf("Error: tidak dapat memperbarui file.\n");
        return 0;
    }

    printf("Alat dengan ID %u berhasil diedit.\n", ID);
    return 1;
}

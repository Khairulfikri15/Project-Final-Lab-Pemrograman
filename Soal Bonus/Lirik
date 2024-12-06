#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PANJANG_BARIS 1024
#define MAX_PANJANG_KATA 100
#define MAX_KATA 1000

// Fungsi untuk menghapus tanda baca dari kata
void clean(char *kata) {
    char cleaned[MAX_PANJANG_KATA];
    int j = 0;

    for (int i = 0; kata[i] != '\0'; i++) {
        if (isalnum(kata[i]) || kata[i] == '-' || kata[i] == '\'') {
            cleaned[j++] = tolower(kata[i]);  // Ubah ke huruf kecil
        }
    }
    cleaned[j] = '\0';  // Akhiri string
    strcpy(kata, cleaned);  // Salin kembali ke kata asli
}

// Fungsi utama
int main() {
    FILE *input_file = fopen("lirik.txt", "r");
    FILE *output_file = fopen("kosa-kata.word", "w");
    char baris[MAX_PANJANG_BARIS];
    char *kata[MAX_KATA];
    int jumlah_kata = 0;

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Membaca judul dari file
    fgets(baris, sizeof(baris), input_file);
    fprintf(output_file, "%s", baris);  // Tulis judul ke file output

    // Membaca setiap baris lirik
    while (fgets(baris, sizeof(baris), input_file)) {
        char *token = strtok(baris, " \n");
        
        while (token != NULL) {
            clean(token);  // Bersihkan kata dari tanda baca

            // Cek apakah kata sudah ada di dalam daftar
            int found = 0;
            for (int i = 0; i < jumlah_kata; i++) {
                if (strcmp(kata[i], token) == 0) {
                    found = 1;
                    break;
                }
            }

            // Jika kata tidak ditemukan, tambahkan ke daftar
            if (!found && strlen(token) > 0) {
                kata[jumlah_kata] = strdup(token);  // Simpan kata
                fprintf(output_file, "%s=\n", kata[jumlah_kata]);  // Tulis ke file output
                jumlah_kata++;
            }

            token = strtok(NULL, " \n");
        }
    }

    // Menutup file
    fclose(input_file);
    fclose(output_file);

    // Membebaskan memori
    for (int i = 0; i < jumlah_kata; i++) {
        free(kata[i]);
    }

    return 0;
}

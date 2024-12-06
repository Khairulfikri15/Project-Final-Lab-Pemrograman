#include "header.h"
#include <stdio.h>
#include <string.h>

char username[100];
char password[100];
char fileUsername[100];
char filePassword[100];
char fileAdmin[100];

int menuLogin(int *admin, char *username, char *password){
    FILE *fileAkun;

    //membuka file
    fileAkun = fopen("akun.txt", "r");
    if (fileAkun == NULL){
        printf("Error: tidak dapat membuka file.\n");
        return 0;
    }
    
    //looping untuk mengecek data di file akun.txt
    while (fscanf(fileAkun, "%s %s %s", fileUsername, filePassword, fileAdmin) != EOF)
    {
        //membandingkan input dengan data file akun
        if ((strcmp(username, fileUsername)== 0) && (strcmp(password, filePassword) == 0)){
            if(strcmp(fileAdmin, "admin") == 0){
                *admin = 1;
            }
            fclose(fileAkun);
            return 1; //login berhasil
        }           
    }
    fclose(fileAkun);  // Pastikan file ditutup setelah selesai
    return 0; // Login gagal
    
}

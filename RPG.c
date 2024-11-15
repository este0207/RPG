#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "global.h"

#define SAVE_NOT_EXIST 0
#define SAVE_EXIST 1

int main() {
    char ligne[1000];
    char name_save[50];
    char name[20];
    char reponse[40];
    int checksave;
    int a = 0;
    int b = 0;


    t_perso persoprincipal; 
    checksave= menudebut(name_save,&persoprincipal);
    
    if (checksave==SAVE_NOT_EXIST)
    {
        intro(ligne);
        getnameandhouse(ligne,name,reponse);
        persoprincipal = attribution(name,reponse);
        save(name_save,&persoprincipal);
    }
    
    intro2(ligne);
    combat(&persoprincipal);
    postfight(&persoprincipal);
    quete2(reponse,&persoprincipal);
    printf("Name save : %s\n",name_save);
    save(name_save,&persoprincipal);
    return 0;
}



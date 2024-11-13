#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


#include "global.h"

int main() {
    char ligne[1000];
    char name[20];
    char house[40];
    int a = 0;
    int b = 0;
    t_perso persoprincipal; 
    menudebut(&persoprincipal);
    intro(ligne);
    getnameandhouse(ligne,name,house);
    persoprincipal = attribution(name,house);
    quete2(house);
    
    

    return 0;
}



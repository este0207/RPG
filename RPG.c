#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


#include "global.h"

int main() {
    genEntropicSeed();
    char ligne[1000];
    char name[20];
    char house[40];
    int a = 0;
    int b = 0;

    // intro(ligne);
    // getnameandhouse(ligne,name,house);
    // t_perso persoprincipal = attribution(name,house);
    // save_player(persoprincipal);
    quete_quiditch();
    

    return 0;
}



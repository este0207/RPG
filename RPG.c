#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "getnameandhouse.c"
#include "histoire.c"
#include "histoire2.c"
#include "attribution.c"
#include "combat.c"
#include "post-fight.c"

int main() {
    char ligne[1000];
    char name[20];
    char house[40];
    int a = 0;
    int b = 0;


    // intro(ligne);
    getnameandhouse(ligne,name,house);
    t_perso persoprincipal = attribution(name,house);
    // intro2(ligne);
    combat(&persoprincipal);
    postfight(ligne,&persoprincipal);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "getnameandhouse.c"
#include "histoire.c"
#include "attribution.c"


int main() {
    char ligne[1000];
    char name[20];
    char house[40];
    int a = 0;
    int b = 0;
    // char buff[1000];

    intro(ligne);
    getnameandhouse(ligne,name,house);
    attribution(name,house);

    return 0;
}



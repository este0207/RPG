#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int screen(char choix[255]) {
    int a;
    printf("1) Bonjour\n");
    printf("2) Charger\n");
    printf("0) Quitter\n");
    printf("|----------------------------------|\n");

    fgets(choix, 255, stdin);
    a = atoi(choix);
    return a;
}

struct player {

    int pv;
    int endurance;
    char name[20];
};


int main() {
    char choix[255];
    int a = 0;
    int b = 0;
    int reponce1 = 0;
    int reponce2 = 0;
    int reponce3 = 0;

    system("clear");

    printf("|----------------------------------|\n");
    printf("|-------------RPG Texutel----------|\n");

    a = screen(choix);

    while (1) {
        system("clear");
        printf("|----------------------------------|\n");
        printf("|-------------RPG Texutel----------|\n");

        
    }

    return 0;
}



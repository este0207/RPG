#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int combat(t_perso* persoprincipal) {
    char ligne[1000];
    int a = 0;
    char choix2[3];
    t_perso troll;
    troll.attaque = 10;
    troll.pv = 100;
    srand(time(NULL));    


    while (troll.pv > 0){    

        system("clear");

        printf(" %s :          Troll :\n vie : %d          vie : %d\n attaque : %d\n defense : %d\n mana : %d\n\n", persoprincipal->nom, persoprincipal->pv,troll.pv, persoprincipal->attaque, persoprincipal->defense, persoprincipal->magie);

        FILE*  fichier = fopen("attaques.txt", "r");
        fread(ligne, 1000, 1, fichier);
        printf("%s\n", ligne);
        fclose(fichier);
        printf("\n");
    
        printf("->");
        fgets(choix2, sizeof(choix2), stdin);
        choix2[strlen(choix2)-1] = 0;
        a = atoi(choix2);

        printf("\n");
        
        switch (a)
            {
            case 1:
                printf("Vous avez utilisez l'attaque 1\n");
                troll.pv -= persoprincipal->attaque; // troll vie --
                printf("la vie du boss est de : %d\n", troll.pv);
                break;
            case 2:
                printf("Vous avez utilisez l'attaque 2\n");
                troll.pv -= persoprincipal->attaque * 2; // troll vie --
                printf("la vie du boss est de : %d\n", troll.pv);
                break;
            default:
                printf("Vous avez choisi une attaque invalide\n");
                return 1;
            }
        int attaque_aleatoire = (rand() % 3) + 1;

        sleep(2);
        printf("\n");

        switch (attaque_aleatoire)
            {
            case 1:
                printf("le boss fais une attack normale\n");
                persoprincipal->pv -= troll.attaque; // perso vie --
                printf("la vie du perso est de : %d\n", persoprincipal->pv);
                break;
            case 2:
                 printf("le boss fais une grosse attack\n");
                persoprincipal->pv -= troll.attaque * 2; // perso vie --
                printf("la vie du perso est de : %d\n", persoprincipal->pv);
                break;
            case 3:
                printf("le boss rate sont attack\n");
                printf("la vie du perso est de : %d\n", persoprincipal->pv);
                break;
            }

        sleep(2);

        if (persoprincipal->pv <= 0){
            printf("vous avez perdu\n");
            return 1;
        }
        if (troll.pv <= 0){
            printf("vous avez gagner\n");
            return 0;
        }
    }
    return 0;
}


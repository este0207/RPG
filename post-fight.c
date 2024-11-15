#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 255


void lireLignes(char *nomFichier, int debut, int fin) {
    FILE *fichier = fopen(nomFichier, "r");  // Ouvrir le fichier en mode lecture
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[256];   // Pour stocker chaque ligne du fichier
    int numeroLigne = 1;

    // Lire chaque ligne du fichier
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (numeroLigne >= debut && numeroLigne <= fin) {
            printf("%s",ligne);  // Affiche les lignes de la plage spécifiée
        }
        numeroLigne++;
        if (numeroLigne > fin) {
            break;  // Quitte la boucle une fois la dernière ligne atteinte
        }
    }

    fclose(fichier);  // Ferme le fichier
}

int postfight(t_perso* persoprincipal) {
    char ligne[1000];
    int a = 0;
    char choix2[10];
    char *nomFichier = "histoire3.txt";  // Nom du fichier à lire
    int ligneDebut = 0;
    int ligneFin = 0;

    t_perso Drago;
    Drago.attaque = 10;
    Drago.pv = 270;
    
    while (persoprincipal->pv > 0) {
        system("clear");

    // [----------------------------]
    // 1) Dans la cour
    // 2) Dans la salle de cours (5min)
    // 3) Vous retournez dans les toilette 
    // 4) Voir les stats
    // 5) Jouer au quidiche
    // [----------------------------]
        FILE *fichier = fopen(nomFichier, "r");
        for (int i = 0; i < 10 && fgets(ligne, sizeof(ligne), fichier) != NULL; i++) {
            printf("%s", ligne);
        }
        fclose(fichier);
        printf("\n");


        printf("-> ");
        fgets(choix2, sizeof(choix2), stdin);
        choix2[strlen(choix2)-1] = 0;
        a = atoi(choix2);

        printf("\n");

        switch (a)
        {
        case 1:  // 1) Dans la cour
            lireLignes(nomFichier, 12, 19);
            printf("-> ");
            fgets(choix2, sizeof(choix2), stdin);
            choix2[strlen(choix2)-1] = 0;
            if (strcmp(choix2, "1") == 0 || strcasecmp(choix2, "oui") == 0) {
                int i = 20;
                while (i < 23)
                {
                    lireLignes(nomFichier, i, i);
                    getchar();
                    i++;
                }
                persoprincipal->pv = 150;
                persoprincipal->defense = 50;
                printf("PV : %d    Shield : %d", persoprincipal->pv, persoprincipal->defense);
                getchar();

                i=0;
                while (i==0)
                {
                
                system("clear");
                // [----------------------------]
                // 1) La forêt
                // 2) Dans sa chambre
                // 3) Dans la salle mystère
                // [----------------------------]
                lireLignes(nomFichier, 25, 30);

                printf("-> ");
                fgets(choix2, sizeof(choix2), stdin);
                choix2[strlen(choix2)-1] = 0;
                a = atoi(choix2);

                
                switch (a)
                {
                case 1:  // 1) La forêt

                    while (Drago.pv > 0 || persoprincipal->pv > 0){ 

                    if (persoprincipal->pv <= 0){
                        printf("Vous n'avez plus de vie !\n");
                        continue;
                        break;
                    }
                    if (persoprincipal->magie <= 0){
                        printf("Vous n'avez plus de mana !\n");
                        persoprincipal->magie = persoprincipal->magie + 10;
                        continue;
                        break;
                    }
                    if (Drago.pv <= 0){
                        system("clear");
                        printf("Vous avez vaincu Drago Malefoy !\n");
                        printf("+10 sur toutes les statistiques\n");
                        printf("Taper entrer pour continuer");
                        getchar();
                        persoprincipal->magie = persoprincipal->magie + 10;
                        persoprincipal->pv = persoprincipal->pv + 10;
                        persoprincipal->defense = persoprincipal->defense + 10;
                        persoprincipal->attaque = persoprincipal->attaque + 10;
                        while (1)
                        {
                        
                        system("clear");
                        lireLignes(nomFichier, 62, 71);
                        persoprincipal->pv = persoprincipal->pv + 50;

                        fgets(choix2, sizeof(choix2), stdin);
                        choix2[strlen(choix2)-1] = 0;
                        a = atoi(choix2);

                        switch (a)
                        {
                        case 1:
                            system("clear");
                            return 0;
                            break;
                        
                         case 2:
                            system("clear");
                            printf(" %s :\n vie : %d\n attaque : %d\n defense : %d\n mana : %d\n\n", persoprincipal->nom, persoprincipal->pv,persoprincipal->attaque, persoprincipal->defense, persoprincipal->magie);
                            printf("Taper entrer pour revenir au menu");
                            getchar();
                            continue;
                        
                        default:
                            break;
                        }

                        }
                    }

                    system("clear");
                    lireLignes(nomFichier, 32, 32);
                    printf(" %s :          Drago :\n vie : %d          vie : %d\n attaque : %d\n defense : %d\n mana : %d\n\n", persoprincipal->nom, persoprincipal->pv,Drago.pv, persoprincipal->attaque, persoprincipal->defense, persoprincipal->magie);
                    lireLignes(nomFichier, 34, 34);

                    fgets(choix2, sizeof(choix2), stdin);
                    choix2[strlen(choix2)-1] = 0;
                    a = atoi(choix2);

                    system("clear");
                    switch (a)
                    {
                    case 1:   // 1) Expectro Patronum(30) 
                        if (persoprincipal->magie < 30){
                            printf("Vous n'avez pas suffisamment de mana pour faire l'attaque Expectro Patronum\n");
                            printf("Tapez Enter pour continuer\n");
                            getchar();
                            continue;
                        }
                        printf("Vous fais l'attaque Expectro Patronum\n");
                        persoprincipal->magie = persoprincipal->magie - 30;
                        persoprincipal->magie = persoprincipal->magie + 10;
                        Drago.pv -= persoprincipal->attaque * 2; // Drago vie --
                        break;
                    case 2:   // 2) Wingardium Leviosa(20)
                    if (persoprincipal->magie < 20){
                            printf("Vous n'avez pas suffisamment de mana pour faire l'attaque Expectro Patronum\n");
                            printf("Tapez Enter pour continuer\n");
                            getchar();
                            continue;
                        }
                        printf("Vous fais l'attaque Wingardium Leviosa\n");
                        persoprincipal->magie = persoprincipal->magie - 20;
                        persoprincipal->magie = persoprincipal->magie + 10;
                        Drago.pv -= persoprincipal->attaque; // Drago vie --
                        break;
                    case 3:   // 3) Coup fort
                        printf("Vous fais l'attaque Coup fort\n");
                        persoprincipal->magie = persoprincipal->magie + 10;
                        Drago.pv -= persoprincipal->attaque; // Drago vie --
                        break;
                    
                    default:
                        printf("Entrer un choix valide !");
                    }
                     int attaque_aleatoire = (rand() % 3) + 1;

                    sleep(2);
                    printf("\n");

                    switch (attaque_aleatoire)
                        {
                        case 1:
                            printf("le boss fais une attack normale\n");
                           persoprincipal->pv -= Drago.attaque; // perso vie --
                            printf("la vie du perso est de : %d\n", persoprincipal->pv);
                            sleep(2);
                            break;
                        case 2:
                            printf("le boss fais une grosse attack\n");
                            persoprincipal->pv -= Drago.attaque * 2; // perso vie --
                            printf("la vie du perso est de : %d\n", persoprincipal->pv);
                            sleep(2);
                            break;
                        case 3:
                            printf("le boss rate sont attack\n");
                            printf("la vie du perso est de : %d\n", persoprincipal->pv);
                            sleep(2);
                            break;
                        }

                    if (persoprincipal->pv <= 0){
                        printf("Vous avez perdu !\n");
                        printf("Tapez Enter pour continuer\n");
                        getchar();
                        break;
                    }
                        }
                    break;

                case 2:   // 2) Dans sa chambre
                    system("clear");
                    lireLignes(nomFichier, 56, 60);

                    fgets(choix2, sizeof(choix2), stdin);
                    choix2[strlen(choix2)-1] = 0;
                    a = atoi(choix2);

                    switch (a)
                    {
                        case 1: 
                            printf("Vous prenez la potion !\n");
                            persoprincipal->pv = persoprincipal->pv + 20;
                            break;
                        case 2: 
                            printf("Vous n'avez rien a faire ici !\n");
                            break;
                        break;
                case 3:  // 3) Dans la salle mystère
                    system("clear");
                    lireLignes(nomFichier, 50, 54);
                    printf("Taper Entrer pour continuer");
                    getchar();
                    break;
                
                default:
                    printf("Entrer un choix valide !");
                
            }
            } 
            }
            }
            
            else if (strcmp(choix2, "2") == 0 || strcasecmp(choix2, "non") == 0) {

                lireLignes(nomFichier, 36, 37);
                getchar();
            }

            break;
        case 2:  // Dans la salle de cours (5min)
            system("clear");
            lireLignes(nomFichier, 39, 43);
            persoprincipal->magie = 100;
            sleep(5);
            lireLignes(nomFichier, 44, 44);
            break;
        case 3:  // 3) Vous retournez dans les toilette 
            system("clear");
            lireLignes(nomFichier, 47, 48);
            printf("Taper Entrer pour revenir au menu");
            getchar();

            break;

        case 4:  // 4) Voir les stats
            system("clear");
            printf(" %s :\n vie : %d\n attaque : %d\n defense : %d\n mana : %d\n\n", persoprincipal->nom, persoprincipal->pv,persoprincipal->attaque, persoprincipal->defense, persoprincipal->magie);
            printf("Taper entrer pour revenir au menu");
            getchar();
            break;
        
        default:
            lireLignes(nomFichier, 43, 44);
            break;
        }

        }

        printf("suite ?\n");

    return 0;
}

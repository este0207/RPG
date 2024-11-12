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
    
        system("clear");

        FILE *fichier = fopen(nomFichier, "r");
        for (int i = 0; i < 8 && fgets(ligne, sizeof(ligne), fichier) != NULL; i++) {
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
        case 1:
            lireLignes(nomFichier, 10, 17);
            printf("-> ");
            fgets(choix2, sizeof(choix2), stdin);
            choix2[strlen(choix2)-1] = 0;
            if (strcmp(choix2, "1") == 0 || strcasecmp(choix2, "oui") == 0) {
                int i = 18;
                while (i < 21)
                {
                    lireLignes(nomFichier, i, i);
                    getchar();
                    i++;
                }
                persoprincipal->pv = 150;
                persoprincipal->defense = 50;
                printf("PV : %d    Shield : %d", persoprincipal->pv, persoprincipal->defense);
                getchar();
                system("clear");
                lireLignes(nomFichier, 23, 28);

                printf("-> ");
                fgets(choix2, sizeof(choix2), stdin);
                choix2[strlen(choix2)-1] = 0;
                a = atoi(choix2);

                switch (a)
                {
                case 1:
                    system("clear");
                    lireLignes(nomFichier, 30, 30);
                    printf(" %s :          Drago :\n vie : %d          vie : %d\n attaque : %d\n defense : %d\n mana : %d\n\n", persoprincipal->nom, persoprincipal->pv,Drago.pv, persoprincipal->attaque, persoprincipal->defense, persoprincipal->magie);

                    break;
                case 2:
                    lireLignes(nomFichier, 29, 30);
                    break;
                case 3:
                    lireLignes(nomFichier, 29, 30);
                    break;
                
                default:
                    printf("Entrer un choix valide !");
                }
                
            } 
            else if (strcmp(choix2, "2") == 0 || strcasecmp(choix2, "non") == 0) {

                lireLignes(nomFichier, 35, 36);
                getchar();
            }

            break;
        case 2:
            lireLignes(nomFichier, 38, 42);
            persoprincipal->magie = 100;
            sleep(300);
            lireLignes(nomFichier, 43, 43);
            break;
        case 3:

            break;
        
        default:
            lireLignes(nomFichier, 42, 43);
            break;
        }

    return 0;
}
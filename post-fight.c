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


int main() {
    char ligne[1000];
    int a = 0;
    char choix2[10];
    char *nomFichier = "histoire3.txt";  // Nom du fichier à lire
    int ligneDebut = 0;
    int ligneFin = 0;
    
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
                while (i < 20)
                {
                    lireLignes(nomFichier, i, i);
                    getchar();
                    i++;
                }
                system("clear");
                lireLignes(nomFichier, 21, 26);

                printf("-> ");
                fgets(choix2, sizeof(choix2), stdin);
                choix2[strlen(choix2)-1] = 0;
                a = atoi(choix2);

                switch (a)
                {
                case 1:
                    lireLignes(nomFichier, 27, 28);
                    break;
                case 2:
                    lireLignes(nomFichier, 29, 30);
                    break;
                
                default:
                    printf("Entrer un choix valide !");
                }
                
            } 
            else if (strcmp(choix2, "2") == 0 || strcasecmp(choix2, "non") == 0) {

                lireLignes(nomFichier, 20, 20);
                getchar();
            }

            break;
        // case 2:
        //     fichier = fopen("histoire3.txt", "r");
        //     for (int i = 10; i < 11; i++)
        //     {
        //         lireLignes(fichier, i, i);
        //         printf("%s", ligne);
        //     }
        //     fclose(fichier);
        //     break;
        // case 3:
        //     fichier = fopen("histoire3.txt", "r");
        //     for (int i = 11; i < 12; i++)
        //     {
        //         lireLignes(fichier, i, i);
        //         printf("%s", ligne);
        //     }
        //     fclose(fichier);
        //     break;
        
        default:
            break;
        }

    return 0;
}



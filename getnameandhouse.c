#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Fonction qui demande le nom et la maison de l'utilisateur
int getnameandhouse(char ligne[1000], char name[20],char maison[40]) {

    // Ouvre le fichier "getname.txt" en lecture et écriture
    FILE*  file = fopen("getname.txt", "r+");

        // Lit la première ligne du fichier et l'affiche
        fgets(ligne,1000, file);
        printf("%s", ligne);
        // Demande le nom de l'utilisateur
        printf("Entrez votre nom (20 caractères max) :\n");
        int i=0;
        while(i==0){
            // Lit la réponse de l'utilisateur
            printf("->");
            fgets(name,20,stdin);
            // Retire le caractère de fin de ligne
            name[strlen(name)-1]=0;
            // Vérifie si le nom est trop long
            if (strlen(name)>20)
            {
                printf("Nom trop long (20 caractères max). Veuillez entrer un nom valide :\n");
            }
            else if(strcmp(name,"")==0){
                printf("Veuillez entrer un nom valide.\n");
            }
            else{
                // Si le nom est valide, sort de la boucle
                i++;
            }
        }
        // Réinitialise la variable i
        i=0;

        // Lit la deuxième ligne du fichier et l'affiche
        fgets(ligne, 1000, file);
        ligne[strlen(ligne)-1]=0;
        printf("%s %s\"\n",ligne,name);
        // Attend que l'utilisateur appuie sur une touche
        getchar();

        // Lit la troisième ligne du fichier et l'affiche
        fgets(ligne, 1000, file);
        ligne[strlen(ligne)-1]=0;
        printf("%s %s,",ligne,name);
        // Attend que l'utilisateur appuie sur une touche
        getchar();
        
        // Lit la quatrième ligne du fichier et l'affiche
        fgets(ligne, 1000, file);
        printf("%s",ligne);
        // Attend que l'utilisateur appuie sur une touche
        getchar();
    // Ferme le fichier
    fclose(file);
    
    // Ouvre le fichier "getmaison.txt" en lecture seule
    FILE * getmaison=fopen("getmaison.txt","r");

    char c;
    int j=0;
    int k=0;

    // Boucle qui permet à l'utilisateur de choisir sa maison
    while (k==0)
    {
        // Affiche le menu des maisons
        system("clear");
        fseek(getmaison,0,SEEK_SET);
        i=0;
        while(i!=1){
            fgets(ligne,1000,getmaison);
            if (strcmp(ligne,"!\n")==0)
            {
                i++;
            }
            else{
            printf("%s",ligne);
            }
        }

        // Demande à l'utilisateur de choisir sa maison
        printf("->");
        fgets(maison,40,stdin);
        // Retire le caractère de fin de ligne
        maison[strlen(maison)-1]=0;
        if (strcmp(maison,"a")==0)
        {   
            j=0;
            // Boucle qui permet à l'utilisateur de choisir sa maison
            while (j==0)
            {             
                // Affiche le menu des maisons
                system("clear");   
                FILE * fichiermaisons=fopen("maison.txt","r");
                fseek(fichiermaisons,0,SEEK_SET);
                while (fgets(ligne,1000,fichiermaisons)!=NULL)
                {
                    printf("%s",ligne);
                }
                printf("\n");
                // Demande à l'utilisateur de choisir sa maison
                printf("->");
                fgets(maison,40,stdin);
                // Retire le caractère de fin de ligne
                maison[strlen(maison)-1]=0;
                if (strcmp(maison,"q")==0)
                {
                    j++;
                }
                else if (strcmp(maison,"b")==0)
                {
                    system("clear");
                    k++;
                    j++;
                    // printf("%d",k);
                }
                else{
                    printf("Veuillez entrer un choix valide. Taper sur ENTER et resaisissez votre choix\n");
                    getchar();
                };
                fclose(fichiermaisons);
            }
        }  
        else if(strcmp(maison,"b")==0)
        {
            k++;
        }
        else(
                    printf("Veuillez entrer un choix valide\n")
        );
        
    }



    i=0;
    // Affiche le reste du fichier "getmaison.txt"
    while (i!=1)
    {
        fgets(ligne,1000,getmaison);
        if (strcmp(ligne,"!\n")==0)
        {
            i++;
        }
        else{
            printf("%s",ligne);
        }

        
    }
    i=0;
    // Boucle qui permet à l'utilisateur de confirmer son choix de maison
    while (i==0)
    {
        printf("->");
        fgets(maison,40,stdin);
        maison[strlen(maison)-1]=0;
        
        if ( strcmp(maison,"1")!=0 && strcmp(maison,"2")!=0 && strcmp(maison,"3")!=0 && strcmp(maison,"4")!=0 && strcmp(maison,"Grifondor")!=0 && strcmp(maison,"Serpentard")!=0 && strcmp(maison,"Serdaigle")!=0 && strcmp(maison,"Poufsoufle")!=0 && strcmp(maison,"grifondor")!=0 && strcmp(maison,"serpentard")!=0 && strcmp(maison,"serdaigle")!=0 && strcmp(maison,"poufsoufle")!=0)
        {
            printf("Veuillez entrer une reponse valide\n");
        }
        else(
            i++);
    }


    // Convertit le nom de la maison en majuscules
    if (strcmp(maison,"1")==0 || strcmp(maison,"grifondor")==0)
    {
        memset(maison,0,40);
        strcpy(maison,"Grifondor");
    }
    else if (strcmp(maison,"2")==0 || strcmp(maison,"serpentard")==0)
    {
        strcpy(maison,"Serpentard");
    }
    else if (strcmp(maison,"3")==0 || strcmp(maison,"serdaigle")==0)
    {
        strcpy(maison,"Serdaigle");
    }
    else if (strcmp(maison,"4")==0 || strcmp(maison,"poufsoufle")==0)
    {
        strcpy(maison,"Poufsoufle");
    }
    
    // Affiche le reste du fichier "getmaison.txt"
    while (fgets(ligne,1000,getmaison)!=NULL)
    {
        printf("%s",ligne);
        usleep(1200000);
    }

    // Affiche le nom de la maison choisi
    printf("%s !\"\n",maison);
    // Attend 3 secondes
    sleep(3);

    // Ferme le fichier
    fclose(getmaison);
    getchar();
    

    // Retourne 0

    return 0;
    
}


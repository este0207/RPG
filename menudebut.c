#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>


void menudebut(t_perso* persoprincipal){
    char ligne[1000];
    char reponse[50];memset(reponse,0,50);
    char lecture[50];memset(lecture,0,50);
    strcpy(lecture,"sauvegarde/");

    FILE * affichagemenu=fopen("menudebut.txt","r");
    while (fgets(ligne,1000,affichagemenu)!=NULL)
    {
        printf("%s",ligne);
    }
    printf("\n");
    fclose(affichagemenu);


    fgets(reponse,50,stdin);
    reponse[strlen(reponse)-1]=0;

    if (strcmp(reponse,"1")==0)
    {
        DIR * save = opendir ("/home/niko/Documents/rpg2/RPG/sauvegarde");
        // DIR * save;
        if (save != NULL)
        {

            
            struct dirent * ent;
            int i=1;
            while ((ent = readdir (save)) != NULL)
            {

                if (strcmp(ent->d_name,".")!=0 && strcmp(ent->d_name,"..")!=0)
                {
                    printf("%d) ",i);
                    printf ("%s\n", ent->d_name);
                    i++;
                }
            }
            closedir (save);
        }
         

        while (1)
        {
            char save[50];memset(save,0,50);
            strcpy(save,lecture);

            fgets(reponse,50,stdin);
            reponse[strlen(reponse)-1]=0;
            strcat(save,reponse);
            printf("%s",save);
            FILE * lecturefichier;
            if ((lecturefichier=fopen(save,"r"))==NULL)
            {
                printf("Erreur veuillez entrer un nom de sauvegarde valide\n\n");
            }
            else if ((lecturefichier=fopen(save,"r"))!=NULL)
            {
                while (fgets(ligne,1000,lecturefichier)!=NULL)
                {
                    printf("%s",ligne);
                }
                fclose(lecturefichier);

                getchar();
            }
            
        }
         
    }

    else if (strcmp(reponse,"2")==0)
    {
        printf("Entrez le nom de la nouvelle sauvegarde (20 caractères max) :\n");
        fgets(reponse,50,stdin);
        reponse[strlen(reponse)-1]=0;
        strcat(lecture,reponse);
        FILE * save=fopen(lecture,"w");
        fclose(save);
        printf("Sauvegarde %s créée ! Appuyez sur ENTER pour lancer le jeu.\n",reponse);
        getchar();
    }

}
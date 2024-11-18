#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "is_folder_empty.c"

int menudebut(char name_save[50],t_perso* persoprincipal){
    char buf[50];
    memset(buf,0,50);
    char ligne[1000];
    char reponse[50];memset(reponse,0,50);
    strcpy(buf,"sauvegarde/");
    
while (1)
{
    system("clear");
    //AFFICHE LE MENU
    FILE * affichagemenu=fopen("menudebut.txt","r");
    while (fgets(ligne,1000,affichagemenu)!=NULL)
    {
        printf("%s",ligne);
    }
    printf("\n");
    fclose(affichagemenu);

    //DEMANDE DE CHARGER UNE PARTIE OU NOUVELLE PARTIE
    while (1)
    {
        fgets(reponse,50,stdin);
        reponse[strlen(reponse)-1]=0;
        if (strcmp(reponse,"1")!=0 && strcmp(reponse,"2")!=0)
        {
            printf("Entrez un choix valide\n\n");
        }
        else{
            break;
        }
        
    }
    system("clear");


    int isEmpty=is_folder_empty("sauvegarde");
    // printf("isEmpty = %d\n\n\n\n",isEmpty);


    //TRAITEMENT DES CHOIX 1 OU 2
    if (strcmp(reponse,"1")==0)
    {
        DIR * save = opendir ("sauvegarde");
        // DIR * save;
        if (save!=NULL)
        {
            struct dirent * ent = readdir (save);
            if(isEmpty==1)
            {
                printf("Il n'existe pas de sauvegarde pour le moment. Appuyez sur ENTER pour revenir au menu\n");
                getchar();
                continue;;
            }
            int i=1;
            printf("Vos sauvegardes :\n\n");
            do
            {

                if (strcmp(ent->d_name,".")!=0 && strcmp(ent->d_name,"..")!=0)
                {
                    printf("%d) ",i);
                    printf ("%s\n", ent->d_name);
                    i++;
                }
            }while ((ent = readdir (save)) != NULL);
            closedir (save);
            
        }

        printf("\nEntrez '!' pour revenir au menu\n\n");
        int k=0;
        while (k==0)
        {
            // printf("K = %d  ",k);
            // printf("reponse = %s\n",reponse);
            // if (strcmp(reponse,"m")==0)
            // {
            //     k++;
            // }
            
            while (1)
            {
                
                fgets(reponse,50,stdin);
                reponse[strlen(reponse)-1]=0;
                if (strlen(reponse)<1)
                {
                    printf("Arrete d'appuyer sur ENTER comme un gogole stp. Marque le nom de la save\n");
                }
                else{
                    break;
                }
                
                
            }
            
            strcpy(name_save,buf);
            strcat(name_save,reponse);

            FILE * lecturefichier;
            if ((lecturefichier=fopen(name_save,"r"))==NULL)
            {
                if (strcmp(reponse,"!")==0)
                {
                    k++;
                    continue;
                }
                else{
                    printf("Erreur veuillez entrer un nom de sauvegarde valide\n\n");
                    // perror("fopenl80");
                }
                
            }
            
            else
            {
                // perror("fopenl84");
                
                fscanf(lecturefichier,"Nom %s\nmaison %s\nattaque %d\ndefense %d\n magie %d\npv %d\nidquete %d",persoprincipal->nom,persoprincipal->maison,&persoprincipal->attaque,&persoprincipal->defense,&persoprincipal->magie,&persoprincipal->pv,&persoprincipal->idquete);
                printf("Sauvegarde %s chargée ! Appuyez sur ENTER pour lancer le jeu.\n",reponse);
                getchar();
                break;
            }
            
        }
        if (k==0)
        {
            return 1;
        }
        
    }   
    else if (strcmp(reponse,"2")==0)
    {
        printf("Entrez le nom de la nouvelle sauvegarde (20 caractères max) :\n");
        while (1)
        {
            fgets(reponse,50,stdin);
            reponse[strlen(reponse)-1]=0;
            if (strlen(reponse)>20)
            {
                printf("Trop de caracteres. Entrez un nouveau nom\n");
                continue;
            }
            if (strlen(reponse)==0)
            {
                printf("Pas assez de caracteres. Entrez un nouveau nom\n"); 
                continue;
            }
            if (strcmp(reponse,"!")==0)
            {
                printf("Le caractère '!' n'est pas autorisé comme nom de sauvegarde. Entrez un autre nom.\n");
                continue;
            }
            
            strcpy(name_save,buf);
            strcat(name_save,reponse);
            // printf("lecture : '%s'",name_save);
            FILE * save;
            if((save=fopen(name_save,"r"))!=NULL)
            {
                printf("Une sauvegarde de ce nom existe déjà. Entrez un nouveau nom\n"); 
                continue;
            }
            else{
                break;
            }
            fclose(save);
        }
        FILE * save;
        save=fopen(name_save,"w+");
        fclose(save);
        // printf("Nom de name_save : %s",name_save);
        printf("Sauvegarde %s créée ! Appuyez sur ENTER pour lancer le jeu.\n",reponse);
        getchar();
        return 0;
    }
}

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int getnameandhouse(char ligne[1000], char name[20],char maison[40]) {

    FILE*  file = fopen("getname.txt", "r+");

        fgets(ligne,1000, file);
        printf("%s", ligne);
        printf("Entrez votre nom (20 caractères max) :\n");
        int i=0;
        while(i==0){
        printf("->");
        fgets(name,20,stdin);
        name[strlen(name)-1]=0;
        if (strlen(name)>20)
        {
            printf("Nom trop long (20 caractères max). Veuillez entrer un nom valide :\n");
        }
        else if(strcmp(name,"")==0){
            printf("Veuillez entrer un nom valide.\n");
        }
        else{
            i++;
        }
        }
        i=0;
        
        fgets(ligne, 1000, file);
        ligne[strlen(ligne)-1]=0;
        printf("%s %s\"\n",ligne,name);
        getchar();

        fgets(ligne, 1000, file);
        ligne[strlen(ligne)-1]=0;
        printf("%s %s ",ligne,name);

        fgets(ligne, 1000, file);
        printf("%s",ligne);
        getchar();
        
        fgets(ligne, 1000, file);
        printf("%s",ligne);
        getchar();
    fclose(file);
    
    FILE * getmaison=fopen("getmaison.txt","r");

    char c;
    int j=0;
    int k=0;

    while (k==0)
    {
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

        printf("->");
        fgets(maison,40,stdin);
        maison[strlen(maison)-1]=0;
        if (strcmp(maison,"a")==0)
        {   
            j=0;
            while (j==0)
            {             
                system("clear");   
                FILE * fichiermaisons=fopen("maison.txt","r");
                fseek(fichiermaisons,0,SEEK_SET);
                while (fgets(ligne,1000,fichiermaisons)!=NULL)
                {
                    printf("%s",ligne);
                }
                printf("\n");
                printf("->");
                fgets(maison,40,stdin);
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
    
    while (fgets(ligne,1000,getmaison)!=NULL)
    {
        printf("%s",ligne);
        usleep(1200000);
    }

    printf("%s !\"\n",maison);
    sleep(3);

    fclose(getmaison);
    return 0;
}

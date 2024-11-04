#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct perso 
{
    char nom [20];
    char maison[40];
    int attaque;
    int defense;
    int magie;
    int pv;
}t_perso;

int attribution(char name[20],char maison[40]){
    
    t_perso persoprincipal;
    strcpy(persoprincipal.nom,name);
    strcpy(persoprincipal.maison,maison);
    if (strcmp(persoprincipal.maison,"Grifondor")==0)
    {
        FILE * grifondor=fopen("grifondor.txt","r");
        fscanf("%d%d%d%d",persoprincipal.attaque,persoprincipal.defense,persoprincipal.magie,persoprincipal.pv);
        fclose(grifondor);
    }
    else if (strcmp(persoprincipal.maison,"Serpentard")==0)
    {
        FILE * serpentard=fopen("serpentard.txt","r");
        fscanf("%d%d%d%d",persoprincipal.attaque,persoprincipal.defense,persoprincipal.magie,persoprincipal.pv);
        fclose(serpentard);
    }
    else if (strcmp(persoprincipal.maison,"Serdaigle")==0)
    {
        FILE * serdaigle=fopen("serdaigle.txt","r");
        fscanf("%d%d%d%d",persoprincipal.attaque,persoprincipal.defense,persoprincipal.magie,persoprincipal.pv);
        fclose(serdaigle);
    }
    else if (strcmp(persoprincipal.maison,"Poufsoufle")==0)
    {
        FILE * poufsoufle=fopen("poufsoufle.txt","r");
        fscanf("%d%d%d%d",persoprincipal.attaque,persoprincipal.defense,persoprincipal.magie,persoprincipal.pv);
        fclose(poufsoufle);
    }
    

}
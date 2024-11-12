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

void save_player(t_perso player){
    FILE* fd = fopen("player","wb");
    fwrite(&player,sizeof(t_perso),1,fd);
    return;
}

t_perso get_player(){
    FILE* fd = fopen("player","rb");
    t_perso player;
    fread(&player,sizeof(t_perso),1,fd);
    return player;
}

t_perso attribution(char name[20],char maison[40]){
    t_perso persoprincipal;
    strcpy(persoprincipal.nom,name);
    strcpy(persoprincipal.maison,maison);
    if (strcmp(persoprincipal.maison,"Grifondor")==0)
    {
        FILE * grifondor=fopen("./maisons/grifondor.txt","r");
        fscanf(grifondor,"Attaque : %d Defense : %d Mana : %d PV : %d",&persoprincipal.attaque,&persoprincipal.defense,&persoprincipal.magie,&persoprincipal.pv);
        fclose(grifondor);
    }
    else if (strcmp(persoprincipal.maison,"Serpentard")==0)
    {
        FILE * serpentard=fopen("./maisons/serpentard.txt","r");
        fscanf(serpentard,"Attaque : %d Defense : %d Mana : %d PV : %d",&persoprincipal.attaque,&persoprincipal.defense,&persoprincipal.magie,&persoprincipal.pv);
        fclose(serpentard);
    }
    else if (strcmp(persoprincipal.maison,"Serdaigle")==0)
    {
        FILE * serdaigle=fopen("./maisons/serdaigle.txt","r");
        fscanf(serdaigle,"Attaque : %d Defense : %d Mana : %d PV : %d",&persoprincipal.attaque,&persoprincipal.defense,&persoprincipal.magie,&persoprincipal.pv);
        fclose(serdaigle);
    }
    else if (strcmp(persoprincipal.maison,"Poufsoufle")==0)
    {
        FILE * poufsoufle=fopen("./maisons/poufsoufle.txt","r");
        fscanf(poufsoufle,"Attaque : %d Defense : %d Mana : %d PV : %d",&persoprincipal.attaque,&persoprincipal.defense,&persoprincipal.magie,&persoprincipal.pv);
        fclose(poufsoufle);
    }
    
    return persoprincipal;
}
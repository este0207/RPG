#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void save(char* save_name,t_perso* persoprincipal){
    FILE * save=fopen(save_name,"w");
    fprintf(save,"nom %s\nmaison %s\nattaque %d\ndefense %d\nmagie %d\npv %d\nidquete %d",
    persoprincipal->nom,persoprincipal->maison,
    persoprincipal->attaque,
    persoprincipal->defense,
    persoprincipal->magie,
    persoprincipal->pv,
    persoprincipal->idquete);
    // Demander a massi pk %ls juste a la ligne d'en haut
    fclose(save);
}

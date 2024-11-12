#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define EVENT_LOOSE_PV '$'

void quete2(char reponse[40]){
    char ligne[1000];
    FILE * quete2=fopen("quete_quiditch.txt","r");
    fread(ligne,1,sizeof(ligne),quete2);
    char* intro = strtok(ligne,"#");
    char* bloc;
    while(bloc = strtok(NULL,"#")){
        printf("##############\n");
        switch (bloc[0])
        {
        case EVENT_LOOSE_PV:
            bloc = &bloc[1];
            printf("\nC'est un choix\n");
            break;
        
        default:
            break;
        }
        printf("%s",bloc);
    }


    
    fclose(quete2);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>



int pertedeballe(float random){
    float chance=0;
    char ligne[1000];
    char chance_buf[10];memset(chance_buf,0,10);

    FILE* chanceadverse=fopen("quete2/pertedeballechance","r");
    fgets(chance_buf,10,chanceadverse);
    chance=atof(chance_buf);

    if (random>chance)
    {
        FILE * pertedeballe=fopen("quete2/pertedeballepasbut","r");
        while(fgets(ligne,1000,pertedeballe)!=NULL){
            ligne[strlen(ligne)-1]=0;
            printf("%s\n",ligne);
            sleep(1);
            fflush(stdout);
        }
        fclose(pertedeballe);
        // printf("random : %f chance : %f\n",random,chance);
        return 1;
    }
    else
    {
        FILE * pertedeballe=fopen("quete2/pertedeballebut","r");
        while(fgets(ligne,1000,pertedeballe)!=NULL){
            ligne[strlen(ligne)-1]=0;
            printf("%s\n",ligne);
            sleep(1);
            fflush(stdout);
        }
        fclose(pertedeballe);
        // printf("random : %f chance : %f\n",random,chance);
        return 2;
    }
    
}
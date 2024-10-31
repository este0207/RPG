#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int nom(char ligne[255], char name[255]) {

    FILE*  file = fopen("questions.txt", "r+");

    fgets(ligne, 255, file);
    printf("%s", ligne);

    fgets(name,255,stdin);
    name[strlen(name)-1]=0;

    fgets(ligne, 255, file);
    ligne[strlen(ligne)-1]=0;
    printf("%s %s\"\n",ligne,name);
    getchar();

    fgets(ligne, 255, file);
    ligne[strlen(ligne)-1]=0;
    printf("%s %s ",ligne,name);

    fgets(ligne, 255, file);
    printf("%s",ligne);
    getchar();
    
    while(fgets(ligne,255,file)!=NULL){
        printf("%s",ligne);
    }

    fclose(file);
    return 0;
}


int main() {
    char ligne[255];
    char name[255];
    int a = 0;
    int b = 0;
    char buff[1000];

    system("clear");

    FILE*  file = fopen("histoire.txt", "r");

    while (fgets(buff, 1000, file) != NULL) {
        buff[strlen(buff) - 1] = '\0';
        printf("%s", buff);
        getchar();
    }

    fclose(file);
    nom( ligne , name);

    return 0;
}



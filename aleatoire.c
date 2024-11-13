#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/random.h>


int genEntropicSeed(){
    int tab[255];
    getentropy(tab,sizeof(tab));
    int seed=0;
    for (int i = 0; i < 255; i++)
    {
        seed=seed+tab[i];
    }
    srand (seed);
}

float aleatoire(float minimum,float maximum){
    float minetmax = minimum+(float)rand()/RAND_MAX*(maximum-minimum); 
    return minetmax;
}
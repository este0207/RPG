#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


#include "aleatoire.c"
#include "pertedeballe.c"

#define EVENT_LOOSE_PV '$'

int quete2(char reponse[40]){
    int decision=0;
    int i=0;
    int k=0;
    int scoreequipe=0;
    int scoreequipeadverse=0;
    char ligne[10000];
    char fichierchance[10];
    float fichierchancefloat=0;

    FILE * quete2=fopen("quete2/quete2.txt","r");
    fread(ligne,1,sizeof(ligne),quete2);

    char* intro = strtok(ligne,"#");
    // for (int i = 0; i < strlen(intro); i++)
    // {
    //     if (intro[i]=='*')
    //     {
    //         getchar();
    //     }
    //     else if(intro[i]=='\n'){

    //     }
    //     else{
    //         printf("%c",intro[i]);
    //         fflush(stdout);
    //         usleep(30000);
    //     }
    // }

    // ICI JE COUPE EN PLUSIEURS PARTIE MON INTRO

    char* menuquete = strtok(NULL,"#");

    char* regledujeu=strtok(NULL,"#");
    switch (regledujeu[0])
    {
    case '\n':
        regledujeu=&regledujeu[1];
        break;
    
    default:
        break;
    }
    
    char* lematchcommmence=strtok(NULL,"#");
    switch (regledujeu[0])
    {
    case '\n':
        regledujeu=&regledujeu[1];
        break;
    
    default:
        break;
    }

    char* un=strtok(NULL,"#");
    char* deux=strtok(NULL,"#");
    char* trois=strtok(NULL,"#");
    char* GO=strtok(NULL,"#");

    char* match=strtok(NULL,"#");
    char match_buf[1000];
    strcpy(match_buf,match);
    
    
    char* matchlancer =strtok(match_buf,"$");
    char * choix1 =strtok(NULL,"$");
    char * choix2 =strtok(NULL,"$");
    char * choix3 =strtok(NULL,"$");
    
    // JE COMMENCE A PRINT ICI

    printf("%s",intro);
    getchar();

    menuquete=&menuquete[1];
    while(i==0)
    {
        system("clear");
        printf("%s",menuquete);

        fgets(reponse,40,stdin);
        reponse[strlen(reponse)-1]=0;

        if (strcmp(reponse,"1")==0)
        {
            system("clear");
            printf("%s",regledujeu);

            fgets(reponse,40,stdin);
            reponse[strlen(reponse)-1]=0;

            if (strcmp(reponse,"")==0)
            {
                continue;
            }
            else if (strcmp(reponse,"b")==0)
            {
                i++;
            }   
        }
        else if (strcmp(reponse,"2")==0)
        {
            break;
        }
        
    }
    printf("%s",lematchcommmence);
    sleep(1.5);
    fflush(stdout);
    printf("%s",un);
    sleep(1);
    fflush(stdout);
    printf("%s",deux);
    sleep(1);
    fflush(stdout);
    printf("%s",trois);
    sleep(1);
    fflush(stdout);
    printf("%s",GO);
    sleep(1);
    fflush(stdout);

    system("clear");
    printf("%s\n",matchlancer);
    getchar();
    
    float random=0;
    // i=0;
    k=0;

    genEntropicSeed();

    // JE COMMENCE LES CHOIX ICI
    int tour=0;
    while(scoreequipe!=3 && scoreequipeadverse!=3 && k==0){
        if (tour!=0)
        {
            system("clear");
        }
        
        decision=0;
        printf("Votre Equipe : %d | %d : Equipe Adverse\n",scoreequipe,scoreequipeadverse);
        printf("%s",choix1);
        printf("%s",choix2);
        printf("%s",choix3);
        printf("\n");
        // i==0;
        while(1){
            fgets(reponse,40,stdin);
            reponse[strlen(reponse)-1]=0;
            if (strcmp(reponse,"1")!=0 && strcmp(reponse,"2")!=0 && strcmp(reponse,"3")!=0)
            {
                printf("Veuilez entrer une bonne réponse\n");
            }
            else{
                break;
            }
        }

        //SI LE JOUEUR PREND LE CHOIX NUMERO 1 
        if (strcmp(reponse,"1")==0)
        {
            FILE * chance=fopen("quete2/chance1.1.txt","r");
            fgets(fichierchance,10,chance);
            fclose(chance);
            fichierchancefloat=atof(fichierchance);
            random=aleatoire(0.0,1.0);
            printf("random : %f et la chance : %f\n",random,fichierchancefloat);
            
            if (random<fichierchancefloat)
            {
                printf("Réussi ! Incroyable, vous avez attrapé le vif d'or ! Votre équipe remporte donc le match !\n");
                k++;
            }
            else if (random>fichierchancefloat)
            {
                printf("Raté !\n");
                random=aleatoire(0.0,1.0);
                decision=pertedeballe(random);
                printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                getchar();
                if (decision==2)
                {
                    scoreequipeadverse++;
                }
                
            }
            
        }

        // SI LE JOUEUR PREND LE CHOIX NUMERO 2
        else if (strcmp(reponse,"2")==0)
        {
            FILE * chance=fopen("quete2/chance1.2.txt","r");
            fgets(fichierchance,10,chance);
            fclose(chance);

            fichierchancefloat=atof(fichierchance);
            // genEntropicSeed();
            random=aleatoire(0.0,1.0);
            printf("random : %f et la chance : %f\n",random,fichierchancefloat);
            
            if (random<fichierchancefloat)
            {
                printf("Réussi !\n");
                // char path[255];memset(path,0,255);
                // sprintf(path,"quete%d/reponse%s/reussite",2,reponse);
                FILE * chance=fopen("quete2/reponse2/reussite","r");
                while (fgets(ligne,1000,chance)!=NULL)
                {
                    printf("%s",ligne);
                }
                fclose(chance);

                while(1){
                    fgets(reponse,40,stdin);
                    reponse[strlen(reponse)-1]=0;
                    if (strcmp(reponse,"1")!=0 && strcmp(reponse,"2")!=0 && strcmp(reponse,"3")!=0)
                    {
                        printf("Veuilez entrer une bonne réponse\n");
                    }
                    else{
                        break;
                    }
                }

                if (strcmp(reponse,"1")==0)
                {
                    FILE * chance=fopen("quete2/reponse2/chance1","r");
                    fgets(fichierchance,10,chance);
                    fclose(chance);
                    fichierchancefloat=atof(fichierchance);
                    // genEntropicSeed();
                    random=aleatoire(0.0,1.0);
                    printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                    if (random<fichierchancefloat)
                    {
                        printf("REUSSI ! Vous avez gagné le match :\n");
                        k++;
                    }
                    else{
                        printf("Raté !\n");
                        decision=pertedeballe(random);
                        printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                        getchar();
                        if (decision==2)
                        {
                            scoreequipeadverse++;
                        }

                    }
                }
                else if (strcmp(reponse,"2")==0)
                {
                    FILE * chance=fopen("quete2/reponse2/chance2","r");
                    fgets(fichierchance,10,chance);
                    fclose(chance);
                    fichierchancefloat=atof(fichierchance);
                    // genEntropicSeed();
                    random=aleatoire(0.0,1.0);
                    printf("random : %f et la chance : %f\n",random,fichierchancefloat);

                    if (random<fichierchancefloat)
                    {
                        printf("REUSSI ! Vous marquer un but pour votre equipe\n");
                        sleep(3);
                        fflush(stdout);
                        scoreequipe++;
                    }
                    else{
                        printf("Raté !\n");
                        random=aleatoire(0.0,1.0);
                        decision=pertedeballe(random);
                        printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                        getchar();
                        if (decision==2)
                        {
                            scoreequipeadverse++;
                        }
                    }
                }
            }
            // else if (random>fichierchancefloat)
            else
            {
                printf("Raté !\n");
                decision=pertedeballe(random);
                if (decision==2)
                {
                    scoreequipeadverse++;
                }
            }
            
        }

        // SI LE JOUEUR PREND LE CHOIX NUMERO 3
        else if(strcmp(reponse,"3")==0)
        {
            FILE * chance=fopen("quete2/chance1.3.txt","r");
            fgets(fichierchance,10,chance);
            fclose(chance);

            fichierchancefloat=atof(fichierchance);
            // genEntropicSeed();
            random=aleatoire(0.0,1.0);
            printf("random : %f et la chance : %f\n",random,fichierchancefloat);

            if (random<fichierchancefloat)
            {
                printf("Réussi !\n");
                FILE * reussite=fopen("quete2/reponse3/reussite","r");
                while (fgets(ligne,1000,chance)!=NULL)
                {
                    printf("%s",ligne);
                }
                fclose(reussite);
            
                while(1){
                        fgets(reponse,40,stdin);
                        reponse[strlen(reponse)-1]=0;
                        if (strcmp(reponse,"1")!=0 && strcmp(reponse,"2")!=0 && strcmp(reponse,"3")!=0)
                        {
                            printf("Veuilez entrer une bonne réponse\n");
                        }
                        else{
                            break;
                        }
                    }
                if (strcmp(reponse,"1")==0)
                {
                    FILE * chance=fopen("quete2/reponse3/chance1","r");
                    fgets(fichierchance,10,chance);
                    fclose(chance);
                    fichierchancefloat=atof(fichierchance);
                    // genEntropicSeed();
                    random=aleatoire(0.0,1.0);
                    printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                    if (random<fichierchancefloat)
                    {
                        printf("Reussi ! Votre équipe gagne le match !\n");
                        k++;
                    }
                    else{
                        printf("Raté !\n");
                        decision=pertedeballe(random);
                        printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                        getchar();
                        if (decision==2)
                        {
                            scoreequipeadverse++;
                        }
                    }
                }
                else if(strcmp(reponse,"2")==0){
                    FILE * chance=fopen("quete2/reponse3/chance2","r");
                    fgets(fichierchance,10,chance);
                    fclose(chance);
                    fichierchancefloat=atof(fichierchance);
                    // genEntropicSeed();
                    random=aleatoire(0.0,1.0);
                    printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                    if (random<fichierchancefloat)
                    {
                        printf("Réussi !\n");
                        FILE * reussite=fopen("quete2/reponse3/reponse2/reussite","r");
                        while (fgets(ligne,1000,chance)!=NULL)
                        {
                            printf("%s",ligne);
                        }
                        fclose(reussite);
                        scoreequipe++;
                        getchar();
                    }
                    else{
                        printf("Raté !\n");
                        random=aleatoire(0.0,1.0);
                        decision=pertedeballe(random);
                        printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                        getchar();
                        if (decision==2)
                        {
                            scoreequipeadverse++;
                        }
                    }
                    
                }
                else if(strcmp(reponse,"3")==0){
                    FILE * chance=fopen("quete2/reponse3/chance3","r");
                    fgets(fichierchance,10,chance);
                    fclose(chance);
                    fichierchancefloat=atof(fichierchance);
                    // genEntropicSeed();
                    random=aleatoire(0.0,1.0);
                    printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                    if (random<fichierchancefloat)
                    {
                        printf("Reussi !\n");
                        FILE * reussite=fopen("quete2/reponse3/reponse3/reussite","r");
                        while (fgets(ligne,1000,reussite)!=NULL)
                        {
                            printf("%s",ligne);
                        }
                        while(1){
                            fgets(reponse,40,stdin);
                            reponse[strlen(reponse)-1]=0;
                            if (strcmp(reponse,"1")!=0 && strcmp(reponse,"2")!=0 && strcmp(reponse,"3")!=0)
                            {
                                printf("Veuilez entrer une bonne réponse\n");
                            }
                            else{
                                break;
                            }
                        }
                        if (strcmp(reponse,"1")==0)
                        {
                            FILE * chance=fopen("quete2/reponse3/reponse3/chance1","r");
                            fgets(fichierchance,10,chance);
                            fclose(chance);
                            fichierchancefloat=atof(fichierchance);
                            // genEntropicSeed();
                            random=aleatoire(0.0,1.0);
                            printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                            if (random<fichierchancefloat)
                            {
                                printf("Reussi ! Vous gagnez la partie\n");
                            }
                            else{
                                printf("Raté !\n");
                                random=aleatoire(0.0,1.0);
                                decision=pertedeballe(random);
                                getchar();
                                if (decision==2)
                                {
                                    scoreequipeadverse++;
                                }
                            }
                            
                        }
                        else if(strcmp(reponse,"2")==0){
                            FILE * chance=fopen("quete2/reponse3/reponse3/chance2","r");
                            fgets(fichierchance,10,chance);
                            fclose(chance);
                            fichierchancefloat=atof(fichierchance);
                            // genEntropicSeed();
                            random=aleatoire(0.0,1.0);
                            printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                            if (random<fichierchancefloat)
                            {
                                printf("Réussi !\n");
                                scoreequipe++;
                                FILE * reussite=fopen("quete2/reponse3/reponse3/reussite","r");
                                while (fgets(ligne,1000,reussite)!=NULL)
                                {
                                    printf("%s",ligne);
                                }
                                sleep(3);
                                fclose(reussite);

                            }
                            else{
                                printf("Raté !\n");
                                random=aleatoire(0.0,1.0);
                                decision=pertedeballe(random);
                                getchar();
                                if (decision==2)
                                {
                                    scoreequipeadverse++;
                                }
                            }
                        }
                        
                    }
                    else{
                        printf("Raté !\n");
                        random=aleatoire(0.0,1.0);
                        decision=pertedeballe(random);
                        getchar();
                        if (decision==2)
                        {
                            scoreequipeadverse++;
                        }
                    }
                    
                }
            }
            else{
                printf("Raté !\n");
                random=aleatoire(0.0,1.0);
                decision=pertedeballe(random);
                printf("random : %f et la chance : %f\n",random,fichierchancefloat);
                getchar();
                if (decision==2)
                {
                    scoreequipeadverse++;
                }
            }
            
        }
    tour++;
    }
    
        
    
    printf("Fin du match. Score final :\nVous :%d | Equipe adverse :%d\n",scoreequipe,scoreequipeadverse);
    
    
    



    
    fclose(quete2);
}
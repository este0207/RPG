#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


#include "aleatoire.c"
#include "pertedeballe.c"

#define EVENT_LOOSE_PV '$'
#define REPONSE_SIZE 40
#define BUF_SIZE 255
#define GAMEOVER 2
#define WIN 1
#define LOSE 3
#define CONTINUE 0


int handle_choices(char* quest_path,int* score_player,int* score_ennemy){
    system("clear");

    /**
     * Init
     */
    char buf[BUF_SIZE];memset(buf,0,BUF_SIZE);

    /**
     * Afficher les choix
     */
    // Afficher les choices
    sprintf(buf,"%s/choices",quest_path);

    FILE* fd_choices = fopen(buf,"r");
    if(fd_choices == NULL){
        perror("Open file ln 33");
        return 1;
    }

    memset(buf,0,BUF_SIZE);
    while(fgets(buf,BUF_SIZE,fd_choices) != NULL){
        printf("%s",buf);
    }
   
    // Get user reponse from question ?
    fgets(buf,BUF_SIZE,stdin);
    buf[strlen(buf)-1] = 0;
    int reponse_value = atoi(buf);


    /**
     * Chance aléatoire de réussite
     */
    // Get chance by reponse

    // open fd chance
    sprintf(buf,"%s/reponse%d/chance",quest_path,reponse_value);
    FILE* fd_chance = fopen(buf,"r");
    if(fd_chance == NULL){
        perror("Open file chance");
        return 1;
    }
    
    // get chance as int
    memset(buf,0,BUF_SIZE);
    fgets(buf,BUF_SIZE,fd_chance);
    float chance = atof(buf);

    float r = rand()/(float)RAND_MAX;

    if(r > chance){
        // lose
        printf("Lose\n");
        return LOSE;
    }
    else
    {
        printf("Win\n");

        // win
        // read loot
        // update player

        // score IF ??
        memset(buf,0,255);
        sprintf(buf,"%s/reponse%d/tire",quest_path,reponse_value);
        if(fopen(buf,"r") != NULL){
            (*score_player)++;
        }
    }

    /**
     * Gestion du game over
     */
    //if gameover exist
    memset(buf,0,255);
    sprintf(buf,"%s/reponse%d/gameover",quest_path,reponse_value);

    if(fopen(buf,"r") != NULL){
        // gameover file exist
        // game should ends
        return GAMEOVER;
    }

    // check if response are available
    // and return continue if so
    memset(buf,0,255);
    sprintf(buf,"%s/reponse%d/reponse1",quest_path,reponse_value);

    if(fopen(buf,"r") == NULL){
        return CONTINUE;
    }

    // There is more questions let's start again handle choice on this quest !
    memset(buf,0,255);
    sprintf(buf,"%s/reponse%d",quest_path,reponse_value);
    handle_choices(buf,score_player,score_ennemy);

    return CONTINUE;
}

void quete_quiditch(){
// buffer des choix du joueur (clavier)
    char reponse[REPONSE_SIZE];

    int decision=0;
    int i=0;
    int k=0;
    int scoreequipe=0;
    int scoreequipeadverse=0;
    char ligne[10000];
    char fichierchance[10];
    float fichierchancefloat=0;
        printf("Score : %d\n",scoreequipe);

    while (scoreequipe < 3)
    {
        int result = handle_choices("quete_quiditch",&scoreequipe,&scoreequipeadverse);

        switch (result)
        {
        case WIN:
            printf("Score : %d\n",scoreequipe);
            break;

        case LOSE:
            // perte_de_balle()
            printf("Lose");
            break;
        case GAMEOVER:
            printf("Gameover");
            return;
            break;
        
        default:
        printf("Default");
            break;
        }
        printf("Score : %d\n",scoreequipe);
    }

    return;

    

    FILE * quete2=fopen("quete_quiditch/quete2.txt","r");
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

        fgets(reponse,REPONSE_SIZE,stdin);
        reponse[strlen(reponse)-1]=0;

        if (strcmp(reponse,"1")==0)
        {
            system("clear");
            printf("%s",regledujeu);

            fgets(reponse,REPONSE_SIZE,stdin);
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


}
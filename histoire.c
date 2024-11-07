#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intro(char* buff){
system("clear");

    FILE*  file = fopen("histoire.txt", "r");

    while (fgets(buff, 1000, file) != NULL) {
        buff[strlen(buff) - 1] = '\0';
        printf("%s", buff);
        getchar();
    }

    fclose(file);
    return 0;
}

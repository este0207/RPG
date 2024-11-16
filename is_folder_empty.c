#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

// int is_folder_empty(char* path_folder);

int is_folder_empty(char* path_folder){
    int isEmpty = 1;

    DIR * folder = opendir (path_folder);
    // DIR * save;
    if (folder != NULL)
    {
        struct dirent * ent = readdir (folder);
        do
        {
            if(strcmp(ent->d_name,".")!=0 && strcmp(ent->d_name,"..")!=0){
                isEmpty = 0;    
            }
        
        } while ((ent= readdir (folder))!=NULL);
        
    
    }
    closedir(folder);
    return isEmpty;
}
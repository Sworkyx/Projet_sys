#include "main.h"//strrchr et strtok

//cette fonction remplace le dernier élement du buffer par \0 au lieu de \n
void n_to_0(char * buffer){
    char * pointer;
    pointer = strrchr(buffer,'\n');
    *pointer = '\0';
}

int traitement_erreur(char * buffer){
    if(buffer[0] == '\n'){
        return 0;
    }
    n_to_0(buffer);
    return 1;
}
#include "main.h"//strrchr

//cette fonction remplace le dernier élement du buffer par \0 au lieu de \n
void n_to_0(char * buffer){
    char * pointer;
    pointer = strrchr(buffer,'\n');
    *pointer = '\0';
}
#include <stdio.h>//printf
#include <stdlib.h>//exit
#include <unistd.h> //fork()
#include <sys/types.h>//pid_t
#include <sys/wait.h>//wait()
#include <string.h>//strcopy et strcat
#define MAX_LENGTH 50


int main(){
    printf("T'es tu promène toi au bord de la rivière qui étincelle au mille tourbillons \n");

    char * buffer = (char *)malloc(MAX_LENGTH);
    while(1){

        printf("$ ");
        fgets(buffer,MAX_LENGTH,stdin);
        n_to_0(buffer);
        
        if(strcmp(buffer,"exit") == 0){
            break;
        }
    }
    
    free(buffer);
    return 0;
}
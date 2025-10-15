#include "main.h"
#define TAILLE 5
#define SIZE 50

// ce parser utilise strtok pour délimiter chaque partie de la ligne de commande
// prend en entrée le buffer et resort un tableau de structre
// dans le tableau argument de la structure il y a également la commande pour que ce tableau soit directement utilisable pour execvp


void parser(char * buffer){

    cmd * tableau_de_commande = init_struct(TAILLE);
    
    char * separateur = " \0";
    char * strToken = strtok(buffer,separateur);

    int cpt_cmd = 0;
    int cpt_arg = 0;

    while(strToken != NULL){

        if(strToken[0] == '-'){
            tableau_de_commande[cpt_cmd].argument[cpt_arg] = strToken;
            cpt_arg++;
        }
        else if(strToken[0] == '&' || strToken[0] == '|'){
            tableau_de_commande[cpt_cmd].separateur = strToken;
            cpt_cmd++;
            cpt_arg = 0;
        }
        else{
            tableau_de_commande[cpt_cmd].command = strToken;
            tableau_de_commande[cpt_cmd].argument[cpt_arg]=strToken;
            cpt_arg++;
        }
        strToken = strtok(NULL,separateur);
    }

    if(strcmp(tableau_de_commande[0].command,"cd") == 0){
        char path[SIZE];
        if(tableau_de_commande[0].argument[1]!=NULL){
            strcpy(path,tableau_de_commande[0].argument[1]);
        }
        if(chdir(path)!=0){
                printf("Impossible de se placer dans le dossier\n");
                
            }
    }
    else{
        execute(tableau_de_commande, cpt_cmd);
    }
    destruct(tableau_de_commande, TAILLE);
}


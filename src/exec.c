#include "main.h"
 
void execute(cmd* ligne_de_commande , int cpt_cmd){

    for(int i = 0; i < cpt_cmd+1; i++){
        pid_t pid = 0;
    pid = fork();
    if(pid == 0){
        execvp(ligne_de_commande[i].command,ligne_de_commande[i].argument);
        exit(0);
    }
    wait(NULL);
    }
}

// dans execl on précise le chemin d'accès puis la commande et ces add on
// le dernier argument doit être nul

// dans execv on précise le chemin d'accès puis la commande et ces add on
// le dernier argument doit être nul

// execvp lance la commande avec les arguments associés placer respectivement en premier et en second argument


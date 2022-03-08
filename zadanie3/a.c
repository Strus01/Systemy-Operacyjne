#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>


void sighandler(int s){
    printf("Sygnal przechwycony\n");
}

int main(int argc, char *argv[]){
    
    int s = atoi(argv[1]);
    
    if(atoi(argv[2]) == 1){
        if(signal(s, SIG_DFL) == SIG_ERR){
        perror("SIGNAL ERROR");
        exit(EXIT_FAILURE);
        }
    }   

    else if(atoi(argv[2]) == 2){    
        if(signal(s, SIG_IGN) == SIG_ERR){
        perror("SIGNAL ERROR");
        exit(EXIT_FAILURE);
        }
    }    

    else if(atoi(argv[2]) == 3){    
        if(signal(s,sighandler) == SIG_ERR){
        perror("SIGNAL ERROR");
        exit(EXIT_FAILURE);
        }
    }
    
    else{
        printf("Podano niepoprawny sygnal\n");
        exit(EXIT_FAILURE);    
    }
    
    
    printf("Czekam na sygnal\n");
    
    pause();
    return 0;
    
}
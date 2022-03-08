#include "komunikaty.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include<time.h>

mqd_t serwer;

void end(void){
    q_close(serwer);
    q_remove(SERWER);
    printf("Program finished\n");
}

void handler(int sig){
    printf("\nSignal has been handled\n");
    exit(0);
}

int main(){
    
    if(atexit(end) != 0){
        perror("ATEXIT ERROR");
        exit(1);
    }

    if(signal(SIGINT, handler) == SIG_ERR){ 
        perror("SIGNAL ERROR");
        exit(2);
    }   

    srand(time(NULL));
    int num = rand() % 8;
    char msg[20];
    char name[5];
    char znak[1];
    char *ptr;
    double token1 = 0, token2 = 0;
    double result = 0;
    int pid;
 
    q_create(SERWER);
    serwer = q_open(SERWER, O_RDONLY);
    printf("Queue %s has been created. Queue descriptor: %d\n", SERWER, serwer); 
    q_getattr(serwer);
    printf("--------------------------------------------------------------------------------\n");

    while(1){
        receive(serwer, msg, sizeof(msg) / sizeof(char));
        printf("Received message: %s\n", msg);
        
        ptr = strtok(msg, " ");
        pid = atoi(ptr);

        int i = 1;
        for(; ptr != NULL; i++){
            ptr = strtok(NULL, " ");

            if(i == 1){
                token1 = atof(ptr);
            }

            if(i == 2){
                sprintf(znak, "%s", ptr);
            }

            if(i == 3){
                token2 = atof(ptr);
            }
        }

        if(znak[0] == '+'){
            result = token1 + token2;
        }

        else if(znak[0] == '-'){
            result = token1 - token2;
        }

        else if(znak[0] == '*'){
            result = token1 * token2;
        }

        else if(znak[0] == '/'){
            if(token2 != 0){
                result = token1 / token2;
            } else { 
                printf("You can't divide by 0\n");
                exit(3);
            }
        }
        
        else{ 
            printf("You gave wrong operator. Please try again.\nYou can only use +, -, *, /\n");
            exit(4);
        }    

        sprintf(name, "/%d", pid);
        mqd_t klient = q_open(name, O_WRONLY);
        
        sleep(num);
        
        sprintf(msg, "%lf", result);
        send(klient, msg, sizeof(msg) / sizeof(char));
        printf("Message was sent: %s\n", msg);
        q_close(klient);
    }

    return 0;
}
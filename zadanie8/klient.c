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

mqd_t klient;
char name[5];

void end(void){
    q_close(klient);
    q_remove(name);
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
    char tmp_msg[15];
    int pid = getpid();
    
    sprintf(name, "/%d", pid);
    q_create(name);
    klient = q_open(name, O_RDONLY);
    printf("Queue %s has been created. Queue descriptor: %d\n", name, klient);
    q_getattr(klient);
    printf("--------------------------------------------------------------------------------\n");
    
    sleep(1);
    mqd_t serwer = q_open(SERWER, O_WRONLY);
    
    printf("Write your equations. Separate the numbers with a space.\n");
    printf("--------------------------------------------------------------------------------\n");
    
    while(fgets(tmp_msg, sizeof(tmp_msg) / sizeof(char), stdin) != NULL){
        sprintf(msg, "%d %s", pid, tmp_msg);
        send(serwer, msg, sizeof(msg) / sizeof(char));
        printf("Message was sent: %s\n", msg);

        sleep(num);

        receive(klient, msg, sizeof(msg) / sizeof(char));
        printf("Received message: %s\n", msg);
        printf("Result is: %s\n", msg);
    }
    
    q_close(serwer);

    return 0;
}
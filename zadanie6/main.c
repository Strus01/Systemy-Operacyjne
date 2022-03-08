#include "semafory.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>

void handler(int sig){
    exit(0);
}

int main(int argc, char* argv[]){
    
    s_create("/semaphore", 1);
    sem_t *sem =s_open("/semaphore");
    printf("Semaphore adress: %p\n", (void *)sem);
    printf("Semaphore value: %d\n", s_value(sem));
    s_close(sem);
    printf("-------------------------------------------------------------\n");
    int test1 = open("numer.txt",O_RDWR|O_CREAT|O_APPEND, 0666);
    if(test1 == -1){
        perror("OPEN ERROR");
        exit(1);
    }
    
    int input = 0;
    if(write(test1, &input, sizeof(int)) == -1){
        perror("WRITE ERROR");
        exit(7);
    }
    close(test1);
    if(signal(SIGINT, handler) == SIG_ERR){
        perror("SIGNAL ERROR");
        exit(2);
    }
    int i = 0;
    for(; i < 4; i++){
        pid_t x = fork();

        if(x == 0){
            execl("wykluczanie.x", "./wykluczanie.x", NULL);
            perror("EXECL ERROR");
            exit(3);
        }

        if(x < 0){
            perror("FORK ERROR");
            exit(4);
        }
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    int test2 = open("numer.txt",O_RDONLY, 0666);
    if(test2 == -1){
        perror("OPEN ERROR");
        exit(1);
    }
    
    if(read(test2, &input, sizeof(int)) == -1){
        perror("READ ERROR");
        exit(5);
    }

    printf("-------------------------------------------------------------\n");

    printf("Input number: %d\n", input);

    if(input == i){
        printf("Input value is correct\n");
    } else { printf("Something went wrong. Input value is not correct\n"); }

    close(test2);

    if(atexit(s_remove) != 0){
        perror("ATEXIT ERROR");
        exit(6);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include "semafory.h"

void s_create(const char* name, unsigned int val){
    sem_t *s = sem_open(name, O_CREAT|O_EXCL, 0644, val);
    if(s == SEM_FAILED){
        perror("SEM_OPEN ERROR");
        exit(1);
    }
    printf("Semaphore created\n");
    printf("Semaphore name: %s\n", name);
}

sem_t *s_open(const char* name, unsigned int val){
    sem_t *s = sem_open(name, val);
    if(s == SEM_FAILED){
        perror("SEM_OPEN ERROR");
        exit(2);
    }
    return s;
}

int s_value(sem_t *s){
    int val;
    if(sem_getvalue(s, &val) == -1){
        perror("SEM_GET_VALUE ERROR");
        exit(3);
    }
    return val;
}

void s_pass(sem_t *s){
    if(sem_post(s) == -1){
        perror("SEM_POST ERROR");
        exit(4);
    } else { printf("Passing semaphore\n"); }
}

void s_release(sem_t *s){
    if(sem_wait(s) == -1){
        perror("SEM_WAIT ERROR");
        exit(5);
    } else { printf("Releasing semaphore\n"); }
}

void s_close(sem_t *s){
    if(sem_close(s) == -1){
        perror("SEM_CLOSE ERROR");
        exit(6);
    }
    printf("Semaphore closed\n");
}

void s_remove(const char* name){
    if(sem_unlink(name) == -1){
        perror("SEM_UNLINK ERROR");
        exit(7);
    }
    printf("Semaphore removed\n");
}
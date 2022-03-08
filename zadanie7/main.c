#include "semafory.h"
#include "pamiec.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/mman.h>

void handler(int sig){
    exit(0);
}
void end(void){
    s_remove("/producentttt");
    s_remove("/konsumentttt");
    sm_remove();
    printf("Program finished\n");
}
int main(int argc, char* argv[]){
    
    s_create("/producentttt", NELE);
    sem_t *producent = s_open("/producentttt", NELE);
    printf("Producer semaphore adress: %p\n", (void *)producent);
    printf("Producer semaphore value: %d\n", s_value(producent));
    printf("-------------------------------------------------------------\n");
    s_create("/konsumentttt", 0);
    sem_t *konsument = s_open("/konsumentttt", 0);
    printf("Consumer semaphore adress: %p\n", (void *)konsument);
    printf("Consumer semaphore value: %d\n", s_value(konsument));
    printf("-------------------------------------------------------------\n");
    int sm = sm_create("/memmmm");
    printf("Shared memory created\n");
    printf("Shared mem fd: %d\n", sm);
    sm_lenght(sm);
    printf("-------------------------------------------------------------\n");
    close(sm);
    s_close(producent);
    s_close(konsument);

    if(argc != 5){
        printf("Podano za mało argumentow\nPrzeczytaj plik README.md\n");
        exit(1);
    }
    
    if(signal(SIGINT, handler) == SIG_ERR){
        perror("SIGNAL ERROR");
        exit(2);
    }
    
    pid_t p = fork();

    if(p == 0){
        execl(argv[1], argv[1], argv[3], NULL);
        perror("EXECL ERROR");
        exit(3);
    }
    
    if(p < 0){
        perror("FORK ERROR");
        exit(4);
    }

    pid_t k = fork();

    if(k == 0){
        execl(argv[2], argv[2], argv[4], NULL);
        perror("EXECL ERROR");
        exit(5);
    }

    if(k < 0){
        perror("FORK ERROR");
        exit(6);
    }

    wait(NULL);
    wait(NULL);

    if(atexit(end) != 0){
        perror("ATEXIT ERROR");
        exit(7);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>
#include "semafory.h"

int main(int argc, char* argv[]){
    srand(time(NULL));
    int num = rand() % 10;
    int input;
    sem_t *sem =s_open("/semaphore");

    printf("Im in private session of procress: %d. Semaphore value: %d\n", getpid(), s_value(sem));
    s_release(sem);
    printf("    Im in critical session of prosess: %d. Semaphore value: %d\n", getpid(), s_value(sem));
    
    int test1 = open("numer.txt",O_RDONLY, 0666);
    if(test1 == -1){
        perror("OPEN ERROR");
        exit(1);
    }

    if(read(test1, &input, sizeof(int)) == -1){
        perror("READ ERROR");
        exit(3);
    }
    printf("        Read value: %d\n", input);

    input++;
    close(test1);
    sleep(num);

    int test2 = open("numer.txt",O_WRONLY, 0666);
    if(test2 == -1){
        perror("OPEN ERROR");
        exit(2);
    }
    if(write(test2, &input, sizeof(int)) == -1){
        perror("WRITE ERROR");
        exit(4);
    }
    close(test2);
    s_pass(sem);
    printf("Im in private session of procress: %d. Semaphore value: %d\n", getpid(), s_value(sem));
    
    return 0;
}
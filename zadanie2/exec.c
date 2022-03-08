#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    int i = 0;
    printf( "Parent UID: %i GID: %i PID: %i PPID: %i PGID: %i\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
    printf("==========================================================\n");
    for (; i < 3; i++){
        pid_t x = fork();
        if (x == 0){
            execl(argv[1], argv[1], NULL);
            perror("EXECL ERROR");
            _exit(2);
        }
        if (x > 0){
            wait(NULL);
        }
        if (x < 0){
            perror("FORK ERROR");
            exit(1);
        }
    }
   return 0; 
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>

int main(){
    int i = 0;
    printf( "Parent UID: %i GID: %i PID: %i PPID: %i PGID: %i\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
    printf("==========================================================\n");
    for (; i < 3; i++){
        pid_t x = fork();
        if (x == 0){
            sleep(5);
            printf( "Child UID: %i GID: %i PID: %i PPID: %i PGID: %i\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
           
        }
        if (x > 0){
            sleep(1);
        }
        if (x < 0){
            perror("FORK ERROR");
            exit(1);
        }
        
    }
   return 0; 
}
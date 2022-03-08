#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>

int main(){
    printf( "UID: %i GID: %i PID: %i PPID: %i PGID: %i\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
    return 0;
}
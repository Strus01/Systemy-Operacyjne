#define _POSIX_C_SOURCE 200112L


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>

int main(int argc, char *argv[]){

    pid_t x = fork();

    if(x == 0){
        execl("./a.x", "a.x", argv[1], argv[2], NULL);
        perror("EXECL ERROR");
        _exit(2);
    } 

    if(x > 0){
        
        sleep(3);

        if(kill(x, 0) == 0){
            kill(x,atoi(argv[1]));
            printf("Wyslano sygnal\n");
        }
        else printf("Nie istnieje proces potomny\n");
    }

    if(x < 0){
        perror("FORK ERROR");
        exit(1);
    }

    return 0;
}

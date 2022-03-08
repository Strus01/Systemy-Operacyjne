#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){

    pid_t x = fork();

    if(x == 0){
        int i = 0;
        int stat;

        setpgid(getpid(), 0);
       
        if(signal(atoi(argv[1]), SIG_IGN) == SIG_ERR){
            perror("SIGNAL ERROR");
            exit(EXIT_FAILURE);
        }
        else printf("Sygnal zignorowany\n");

        for(; i < 3; i++){
            pid_t a = fork();

            if(a == 0){
                execl("./a.x", "a.x", argv[1], argv[2], NULL);
                perror("EXECL ERROR");
                _exit(2);
            }

            if(a > 0){
                sleep(1);
            }

            if(a < 0){
                perror("FORK ERROR");
                exit(1);
            }
        }
        
        wait(&stat);
        if(WIFEXITED(stat))
        printf("Exit status: %d\n", WEXITSTATUS(stat));

        wait(&stat);
        if(WIFEXITED(stat))
        printf("Exit status: %d\n", WEXITSTATUS(stat));
        
        wait(&stat);
        if(WIFEXITED(stat))
        printf("Exit status: %d\n", WEXITSTATUS(stat));
        
    }

    if(x > 0){
        
        sleep(10);

        if(kill(x, 0) == 0){
            kill(-getpgid(x),atoi(argv[1]));
            printf("Wyslano sygnal\n");
        }
        else printf("Nie istnieje proces potomny\n");

        sleep(2);
    }

    if(x < 0){
        perror("FORK ERROR");
        exit(1);
    }

    return 0;
}
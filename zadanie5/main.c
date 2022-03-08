#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include<string.h>
#include<time.h>

void koniec(void){
    unlink("fifo");
    printf("Usunieto potok i zakonczono program\n");
}

int main(int argc, char* argv[]){

    if(argc != 3){
        printf("Podano za mało argumentow\nPrzeczytaj plik README.md\n");
        exit(1);
    }

    if(mkfifo("fifo", 0777) == -1){
        perror("MKFIFO ERROR");
        exit(2);
    }

    pid_t x = fork();

    if (x == 0){
        execl("./producent.x","producent.x", argv[1], "fifo", NULL);
        perror("EXECL ERROR");
        _exit(3);
    }
    
    if(x < 0){
        perror("FORK ERROR");
        exit(4);
    }

    pid_t y = fork();

    if (y == 0){
        execl("./konsument.x","konsument.x", argv[2], "fifo", NULL);
        perror("EXECL ERROR");
        _exit(5);
    }

    if(y < 0){
        perror("FORK ERROR");
        exit(6);
    }

    wait(NULL);
    wait(NULL);

    if(atexit(koniec) != 0){
        perror("ATEXIT ERROR");
        exit(7);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<time.h>

#define BUF_SIZE 10

int main(int argc, char* argv[]){
    char bufread[2];
    int f = open("fifo", O_RDWR);
    int InOpen = open(argv[1], 0);
    int i = 0;
    srand(time(NULL));
    int num = rand() % 10;
    
    if(InOpen == -1 || f == -1){
            perror("OPEN ERROR");
            exit(1);
        }

    for(; i < BUF_SIZE / sizeof(bufread); i++){

        sleep(num);

        if(read(InOpen, bufread, sizeof(bufread)) == -1){
            perror("READ ERROR");
            exit(2);
        }

        printf("Przeczytano tekst z pliku in.txt: %s\n", bufread);

        if(write(f, bufread, sizeof(bufread)) == -1){
            perror("WRITE ERROR");
            exit(3);
        }  
    } 
    close(InOpen);
    return 0;   
}
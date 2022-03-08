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
    int OutOpen = open(argv[2], O_RDWR|O_CREAT|O_APPEND, 0666);
    int f = open("fifo", O_RDWR);
    int i = 0;
    srand(time(NULL));
    int num = rand() % 10;
    
    if(OutOpen == -1 || f == -1){
            perror("OPEN ERROR");
            exit(1);
        }
    
    for(; i < BUF_SIZE / sizeof(bufread); i++){
        
        sleep(num);

        if(read(f, bufread, sizeof(bufread)) == -1){
            perror("READ ERROR");
            exit(2);
        }  

        if(write(OutOpen, bufread, sizeof(bufread) == -1)){
            perror("WRITE ERROR");
            exit(3);
        }

        printf("Wyslano tekst do pliku out.txt: %s\n", bufread);        
    }    
    close(OutOpen);
    return 0;
}
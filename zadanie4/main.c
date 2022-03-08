#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include<string.h>
#include<time.h>

#define BUF_SIZE 10

int main(int argc, char* argv[]){
    
    int filedes[2];
    char bufread[2];
    srand(time(NULL));
    int num = rand() % 10;

    if(argc != 3){
        printf("Podano za mało argumentow\nPrzeczytaj plik README.md\n");
        exit(1);
    }

    if(pipe(filedes) == -1){
        perror("PIPE ERROR");
        exit(2);
    }
    
    int InOpen = open(argv[1], 0);
    int OutOpen = open(argv[2], O_RDWR|O_CREAT|O_APPEND, 0666);

    if(InOpen == -1 || OutOpen == -1){
        perror("OPEN ERROR");
        exit(3);
    }

    pid_t x = fork();

    if(x == 0){
        close(filedes[1]);
        int i = 0;
        for(; i < BUF_SIZE / sizeof(bufread); i++){
            
            sleep(num);
            
            if(read(filedes[0], bufread, sizeof(bufread)) == -1){
                perror("READ ERROR");
                exit(4);
            }  
             
            if(write(OutOpen, bufread, sizeof(bufread) == -1)){
                perror("WRITE ERROR");
                exit(5);
            }
            
            printf("Wyslano tekst do pliku out.txt: %s\n", bufread);  
        } 
        close(filedes[0]);
        close(OutOpen);
    }

    if(x > 0){
        close(filedes[0]);
        int i = 0;
        for(; i < BUF_SIZE / sizeof(bufread); i++){
            
            sleep(num);
            
            if(read(InOpen, bufread, sizeof(bufread)) == -1){
                perror("READ ERROR");
                exit(6);
            }
            
            printf("Przeczytano tekst z pliku in.txt: %s\n", bufread);
            
            if(write(filedes[1], bufread, sizeof(bufread)) == -1){
                perror("WRITE ERROR");
                exit(7);
            }  
        }   
        close(filedes[1]);
        close(InOpen);
        wait(NULL);
    }

    if(x < 0){
        perror("FORK ERROR");
        exit(8);
    }

    return 0;
}    
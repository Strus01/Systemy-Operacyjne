#include "semafory.h"
#include "pamiec.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <string.h>

#define N 2

int main(int argc, char* argv[]){

    char bufread[N];
    int InOpen = open(argv[1], O_RDONLY, 0);
    if(InOpen == -1){
        perror("OPEN ERROR");
        exit(1);
    }
    
    Sharedmem *map;
    int sm = sm_open("/memmmm");
    sm_lenght(sm);
    map = sm_map(sm);
    map -> in = 0;
    map -> out = 0;
    
    sem_t *producent = s_open("/producentttt", NELE);
    sem_t *kosnument = s_open("/konsumentttt", 0);
    
    printf("Producer: Im in private session of procress: %d. Semaphore value: %d\n", getpid(), s_value(producent));

    while(1){
        s_release(producent);
        printf("    Producer: Im in critical session of prosess: %d. Semaphore value: %d\n", getpid(), s_value(producent));
        
        memset(bufread, '-', sizeof(bufread));

        int data = read(InOpen, bufread, sizeof(bufread));
        if(data == -1){
            perror("READ ERROR");
            exit(2);
        }
        
        if(data == 0){
            map -> buf[map -> in][0] = '\0';
            map -> in = (map -> in + 1) % NBUF;
            s_pass(kosnument);
            break;
        }
        
        printf("Producer wrote: \n");
        write(STDOUT_FILENO, bufread, sizeof(bufread));
        printf("\n");

        memcpy(map -> buf[map -> in], bufread, sizeof(bufread));
        map -> in = (map -> in + 1) % NBUF;

        s_pass(kosnument);
        printf("Producer: Im in private session of procress: %d. Semaphore value: %d\n", getpid(), s_value(producent));
    }
   
    close(InOpen);
    sm_unamp(map);
    close(sm);
    s_close(producent);
    return 0;
}
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
    int OutOpen = open(argv[1], O_WRONLY, 0644);
    if(OutOpen == -1){
        perror("OPEN ERROR");
        exit(1);
    }
    
    Sharedmem *map;
    int sm = sm_open("/memmmm");
    sm_lenght(sm);
    map = sm_map(sm);
    map -> in = 0;
    map -> out = 0;

    sem_t *konsument = s_open("/konsumentttt", 0);
    sem_t *producent = s_open("/producentttt", NELE);
    
    printf("Consumer: Im in private session of procress: %d. Semaphore value: %d\n", getpid(), s_value(konsument));

    while(1){
        s_release(konsument);
        printf("    Consumer: Im in critical session of prosess: %d. Semaphore value: %d\n", getpid(), s_value(konsument));

        memset(bufread, '-', sizeof(bufread));

        if(map -> buf[map -> out][0] == '\0'){
            s_pass(producent);
            break;
        }
        
        memcpy(bufread, map -> buf[map -> out], sizeof(bufread));

        map -> out = (map -> out + 1) % NBUF;

        if(write(OutOpen, bufread, sizeof(bufread)) == -1){
            perror("WRITE ERROR");
            exit(3);
        }
        
        sleep(1);
        printf("Consumer wrote: \n");
        write(STDOUT_FILENO, bufread, sizeof(bufread));
        printf("\n");

        s_pass(producent);
        printf("Consumer: Im in private session of procress: %d. Semaphore value: %d\n", getpid(), s_value(konsument));
    }
    close(OutOpen);
    sm_unamp(map);
    close(sm);
    s_close(konsument);
    return 0;
}
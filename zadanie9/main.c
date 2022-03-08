#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <time.h>

#define XMAX 55

#define THREADS 3
#define CRITICAL 3

int COUNT = 0; 

pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;

void* threads(void* t){
    srand(time(NULL));
    int num = 1 + rand() % 3;
    int id;
    int count;
    int i;
    id = *(int*)t;

    sleep(THREADS + 1);
    for(int i = 0; i < CRITICAL; i++){
        printf("\033[%d;%dH", id + THREADS + CRITICAL + 1, 1);
        printf("Thread: %d in private section nr: %d\n", id + 1, i + 1);
        
        sleep(num);

        pthread_mutex_lock(&mymutex);
        
        printf("\033[%d;%dH\033[2K", id + THREADS + CRITICAL + 1, 1);
        printf("\033[%d;%dH", id + THREADS + CRITICAL + 1, XMAX);
        printf("Thread: %d in critical section nr: %d\n", id + 1, i + 1);
        
        count = COUNT;
        
        sleep(num);
        
        count++;
        COUNT = count;

        printf("\033[%d;%dH\033[2K", THREADS * CRITICAL + 3, 1);
        printf("\033[%d;%dH", THREADS * CRITICAL + 3, 1);
        printf("Counter value: %d\n", count);

        printf("\033[%d;%dH", id + THREADS + CRITICAL + 1, XMAX);
        printf("                                              ");
        
        pthread_mutex_unlock(&mymutex);
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    
    pthread_t thread_id[THREADS];
    static int id;
    int i;

    printf("\033c");

    printf("Mutex adress: %p\n", (void*)&mymutex);

    for(i = 0; i < THREADS; i++){
        id = i;
        if(pthread_create(&(thread_id[i]), NULL, &threads, (void*)&id) != 0){
            perror("PTHREAD CREATE ERROR");
            exit(1);
        }
        
        printf("Thread nr: %d id: %ld\n", i + 1, thread_id[i]);
        sleep(1);
    }

    printf("-----------------------------------------------------------------------------------------\n");
    printf("\033[%d;%dH", id + THREADS + 1, 1);
    printf("[ PRIVATE SECTION ]\n");
    printf("\033[%d;%dH", id + THREADS + 1, XMAX);
    printf("[ CRITICAL SECTION ]\n");

    for(i = 0; i < THREADS; i++){
        if(pthread_join(thread_id[i], NULL) != 0){
            perror("PTHREAD_JOIN ERROR");
            exit(2);
        }
    }

    pthread_mutex_destroy(&mymutex);

    printf("\033[%d;%dH\033[2K", id + THREADS + 1, 1);
    printf("\033[%d;%dH\033[2K", id + THREADS + 1, XMAX);
    printf("\033[%d;%dH", id + THREADS + 1, 1);
    printf("Global iterator value: %d\n", COUNT);

    if(COUNT == THREADS * CRITICAL){
        printf("Counter has expected value\n");
    } else {
        printf("Something went wrong. Counter has bad value\n");
    }

    printf("\033[%d;%dH\033[2K", THREADS * CRITICAL + 3, 1);
    return 0;
}
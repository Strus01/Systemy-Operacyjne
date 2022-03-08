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
#include <string.h>

#define XMAX 55
#define YMAX 20
#define THREADS 5
#define CRITICAL 3

int numbers[THREADS];
int choosing[THREADS];
int COUNT = 0;

void lock(int t){
    choosing[t] = 1;
    int max = 0;
    int i;

    for(i = 0; i < THREADS; i++){
        int number = numbers[i];
        if(number > max){
            max = number;
        }
    }

    numbers[t] = max + 1;
    choosing[t] = 0;

    for(i = 0; i < THREADS; i++){
        while(choosing[i]) {}

        while(numbers[i] != 0 && (numbers[i] < numbers[t] || (numbers[i] == numbers[t] && i < t))) {}
    }
}

void unlock(int t){
    numbers[t] = 0;
}

void* threads(void* t){
    srand(time(NULL));
    int num = 1 + rand() % 3;
    int id;
    int count;
    int i;
    id = *(int*)t;

    sleep(THREADS + 1);
    
    for(i = 0; i < CRITICAL; i++){
        printf("\033[%d;%dH", id + THREADS + CRITICAL, 1);
        printf("Thread: %d in private section nr: %d\n", id + 1, i + 1);
        
        sleep(num);
        lock(id);
        
        printf("\033[%d;%dH\033[2K", id + THREADS + CRITICAL, 1);
        printf("\033[%d;%dH", id + THREADS + CRITICAL, XMAX);
        printf("Thread: %d in critical section nr: %d\n", id + 1, i + 1);
        count = COUNT;

        sleep(num);

        count++;
        COUNT = count;
        
        printf("\033[%d;%dH\033[2K", YMAX, 1);
        printf("\033[%d;%dH", YMAX, 1);
        printf("Counter value: %d\n", count);

        printf("\033[%d;%dH", id + THREADS + CRITICAL, XMAX);
        printf("                                              ");
        
        unlock(id);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    
    pthread_t thread_id[THREADS];
    static int id;
    int i;

    printf("\033c");

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
    printf("\033[%d;%dH", THREADS + 2, 1);
    printf("[ PRIVATE SECTION ]\n");
    printf("\033[%d;%dH", THREADS + 2, XMAX);
    printf("[ CRITICAL SECTION ]\n");

    for(i = 0; i < THREADS; i++){
        if(pthread_join(thread_id[i], NULL) != 0){
            perror("PTHREAD_JOIN ERROR");
            exit(2);
        }
    }

    printf("\033[%d;%dH\033[2K", id + THREADS , 1);
    printf("\033[%d;%dH\033[2K", id + THREADS , XMAX);
    printf("\033[%d;%dH", id + THREADS, 1);
    printf("Global iterator value: %d\n", COUNT);

    if(COUNT == THREADS * CRITICAL){
        printf("Counter has expected value\n");
    } else {
        printf("Something went wrong. Counter has bad value\n");
    }

    printf("\033[%d;%dH\033[2K", YMAX, 1);
    
    return 0;
}    
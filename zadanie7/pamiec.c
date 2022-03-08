#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "pamiec.h"

int sm_create(const char* name){
    int fd = shm_open(name, O_RDWR|O_CREAT|O_EXCL, 0644);
    if(fd == -1){
        perror("SHM_OPEN ERROR");
        exit(1);
    }
    return fd;
}

int sm_open(const char* name){
    int fd = shm_open(name, O_RDWR, 000);
    if(fd == -1){
        perror("SHM_OPEN ERROR");
        exit(2);
    }
    return fd;
}

void sm_lenght(int fd){
    if(ftruncate(fd, sizeof(Sharedmem)) == -1){ 
        perror("FTRUNCATE ERROR");
        exit(3);
    }
    printf("Shared memory size: %ld\n", sizeof(Sharedmem));
}

void sm_remove(void){
    if(shm_unlink("/memmmm") == -1){
        perror("SHM_UNLINK");
        exit(4);
    }
    printf("Shared memory removed\n");
}

void *sm_map(int fd){
    Sharedmem *m_addr = (Sharedmem *) mmap(NULL, sizeof(Sharedmem), PROT_EXEC|PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(m_addr == MAP_FAILED){
        perror("MMAP ERROR");
        exit(5);
    }
    printf("Shared memory mapped\n");
    return m_addr;
}

void sm_unamp(void *addr){
    if(munmap(addr, sizeof(Sharedmem)) == -1){
        perror("MUNMAP ERROR");
        exit(6);
    }
    printf("Shared memory unmapped\n");
}


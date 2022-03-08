#ifndef PAMIEC_H
#define PAMIEC_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

//Struktura do pamieci dzielonej
#define NELE 2
#define NBUF 5

typedef struct{
    char buf [NBUF] [NELE];
    int in, out;
} Sharedmem;

//Tworzenie oamieci dzielonej 
int sm_create(const char* name);

//Otwieranie pamieci dzielonej
int sm_open(const char* name);

//Podanie dlugosci
void sm_lenght(int fd);

//Usuwanie pamieci dzielonej
void sm_remove(void);

//Mapowanie pamieci dzielonej
void *sm_map(int fd);

//Usuwanie mapowania pamieci dzielonej
void sm_unamp(void *addr);

#endif //PAMIEC_H
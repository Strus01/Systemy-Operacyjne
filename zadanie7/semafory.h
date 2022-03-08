#ifndef SEMAFORY_H
#define SEMAFORY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <unistd.h>

//Tworzenie semafora
void s_create(const char* name, unsigned int val);

//Otwieranie semafora
sem_t *s_open(const char* name, unsigned int val);

//Wartość semafora
int s_value(sem_t *s);

//sem_posts
void s_pass(sem_t *s);

//sem_wait
void s_release(sem_t *s);

//Zamknięcie semafora
void s_close(sem_t *s);

//Usuwanie samofora
void s_remove(const char* name);

#endif //SEMAFORY_H
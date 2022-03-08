#ifndef SEMAFORY_H
#define SEMAFORY_H

#include<stdlib.h>
#include<semaphore.h>

//Tworzenie semafora
void s_create(const char* name, unsigned int val);

//Otwieranie semafora
sem_t *s_open(const char* name);

//Wartość semafora
int s_value(sem_t *s);

//sem_posts
void s_pass(sem_t *s);

//sem_wait
void s_release(sem_t *s);

//Zamknięcie semafora
void s_close(sem_t *s);

//Usuwanie samofora
void s_remove(void);

#endif //SEMAFORY_H
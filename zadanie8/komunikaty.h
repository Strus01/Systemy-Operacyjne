#ifndef KOMUNIKATY_H
#define KOMUNIKATY_H

#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERWER "/s"

// Tworzenie kolejki komunikatow
void q_create(const char* name);

// Otwieranie kolejki komunikatow
mqd_t q_open(const char* name, int oflag);

// Zamykanie kolejki komunikatow
void q_close(mqd_t filedes);

// Usuwanie kolejki komunikatow
void q_remove(const char* name);

// Pobieranie atrybotow kolejki komunikatow
void q_getattr(mqd_t filedes);

// Wysylanie komunikatu
void send(mqd_t filedes, const char *msgptr, size_t msglen);

// Odbieranie komunikatu
void receive(mqd_t filedes, char *msgptr, size_t msglen);

#endif // KOMINIKATY_H
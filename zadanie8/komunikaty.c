#include "komunikaty.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>
#include <errno.h>

extern int errno;

void q_create(const char* name){
    struct mq_attr q_attr;

    q_attr.mq_flags = 0;
    q_attr.mq_maxmsg = 5;
    q_attr.mq_msgsize = 20;
    q_attr.mq_curmsgs = 0;
    
    mqd_t filedes = mq_open(name, O_EXCL|O_CREAT|O_RDWR, 0644, &q_attr);
    
    if(filedes == -1){
        perror("MQ_OPEN ERROR");
        exit(1);
    }
    mq_close(filedes);
}

mqd_t q_open(const char* name, int oflag){
    mqd_t filedes = mq_open(name, oflag);
    if(filedes == -1){
        printf("ERRNO: %d\n", errno);
        perror("MQ_OPEN ERROR");
        exit(2);
    }
    return filedes;
}

void q_close(mqd_t filedes){
    if(mq_close(filedes) == -1){
        perror("MQ_CLOSE ERROR");
        exit(3);
    }
}

void q_remove(const char* name){
    if(mq_unlink(name) == -1){
        perror("MQ_UNLINK ERROR");
        exit(4);
    }
}

void q_getattr(mqd_t filedes){
    struct mq_attr q_attr;
    if(mq_getattr(filedes, &q_attr) == -1){
        perror("MQ_GETATTR ERROR");
        exit(5);
    }
    printf("Queue attributes: \n");
    printf("Queue flag: %ld\n", q_attr.mq_flags);
    printf("Queue max number of messsages: %ld\n", q_attr.mq_maxmsg);
    printf("Queue max size of message: %ld\n", q_attr.mq_msgsize);
    printf("Queue current number of messages: %ld\n", q_attr.mq_curmsgs);
}

void send(mqd_t filedes, const char *msgptr, size_t msglen){
    if(mq_send(filedes, msgptr, msglen, 0) == -1){
        perror("MQ_SEND ERROR");
        exit(6);
    }
}

void receive(mqd_t filedes, char *msgptr, size_t msglen){
    if(mq_receive(filedes, msgptr, msglen, 0) == -1){
        perror("MQ_RECIVE ERROR");
        exit(7);
    }
}


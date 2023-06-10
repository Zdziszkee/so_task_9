//
// Created by Zdziszkee on 6/10/2023.
//

#include "thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

pthread_t create_posix_thread(void *fun(void *), void *arg) {
    pthread_t thread;
    int status = pthread_create(&thread, NULL, fun, arg);
    if (status == 0) return thread;
    switch (status) {
        case EAGAIN: {
            perror("Failed to create posix thread\nSystem limit of pthread or processes over flow\n");
            exit(EXIT_FAILURE);
        }
        case ENOMEM: {
            perror("Failed to create posix thread\nOut of memory to create new pthread\n");
            exit(EXIT_FAILURE);
        }
        case EINVAL: {
            perror("Failed to create posix thread\nIncorrect value of attribute argument\n");
            exit(EXIT_FAILURE);
        }
        default: {
            perror("Failed to create posix thread\n");
            exit(EXIT_FAILURE);
        }
    }


}

void join_posix_thread(pthread_t thread, void **status) {
    if (pthread_join(thread, status) != 0) {
        perror("Failed to join threads");
        exit(EXIT_FAILURE);
    }
}

void create_mutex(pthread_mutex_t *mutex, const pthread_mutexattr_t *attribute) {
    int status = pthread_mutex_init(mutex, attribute);
    if (status == EINVAL) {
        perror("Failed to init mutex\nInvalid arguments\n");
        exit(EXIT_FAILURE);
    } else if (status != 0) {
        perror("Failed to init mutex\n");
        exit(EXIT_FAILURE);
    }
}

void delete_mutex(pthread_mutex_t *mutex) {
    int status = pthread_mutex_destroy(mutex);
    if (status == EBUSY) {
        perror("Failed to destroy mutex\nMutex doesn't exists\n");
        exit(EXIT_FAILURE);
    } else if (status != 0) {
        perror("Failed to destroy mutex\n");
        exit(EXIT_FAILURE);
    }
}

void lock_mutex(pthread_mutex_t *mutex) {
    if (pthread_mutex_lock(mutex) != 0) {
        perror("Failed to lock mutex\n");
        exit(EXIT_FAILURE);
    }
}

void unlock_mutex(pthread_mutex_t *mutex) {
    if (pthread_mutex_unlock(mutex) != 0) {
        perror("Failed to unlock mutex\n");
        exit(EXIT_FAILURE);
    }
}


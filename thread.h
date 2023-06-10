//
// Created by Zdziszkee on 6/10/2023.
//

#ifndef SO_TASK_9_THREAD_H
#define SO_TASK_9_THREAD_H
#include <pthread.h>

/* to create new thread */
pthread_t create_posix_thread(void *fun(void *), void *arg);

/* to wait for end of thread */
void join_posix_thread(pthread_t thread, void **status);

/* for initiate mutex */
void create_mutex(pthread_mutex_t *mutex, const pthread_mutexattr_t *attribute);

/* to destroy mutex */
void delete_mutex(pthread_mutex_t *mutex);

/* to lock mutex */
void lock_mutex(pthread_mutex_t *mutex);

/* to unlock mutex */
void unlock_mutex(pthread_mutex_t *mutex);

#endif //SO_TASK_9_THREAD_H

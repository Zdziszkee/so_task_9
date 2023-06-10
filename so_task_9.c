#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "thread.h"


int GLOBAL_COUNTER = 0;
long THREADS;
long SECTIONS;
pthread_mutex_t MUTEX;

void *thread(void *arg) {
    int thread_number = *((int *) arg);

    for (int i = 0; i < SECTIONS; ++i) {
        sleep(1);
        lock_mutex(&MUTEX);
        int local_counter = GLOBAL_COUNTER;
        local_counter++;
        GLOBAL_COUNTER = local_counter;
        unlock_mutex(&MUTEX);
        printf("Thread number: %d, number value: %d \n", thread_number, GLOBAL_COUNTER);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Wrong number of arguments expected 2, received %d", argc - 1);
        exit(EXIT_FAILURE);
    }
    THREADS = strtol(argv[1], NULL, 10);
    SECTIONS = strtol(argv[2], NULL, 10);

    unsigned long thread_ids[THREADS];
    create_mutex(&MUTEX, NULL);
    for (int i = 0; i < THREADS; ++i) {
        thread_ids[i] = create_posix_thread(thread, &i);
    }
    for (int i = 0; i < THREADS; ++i) {
        join_posix_thread(thread_ids[i], NULL);
    }
    delete_mutex(&MUTEX);

    printf("Number value expected %ld, number value received %d\n", THREADS * SECTIONS, GLOBAL_COUNTER);
    return 0;
}

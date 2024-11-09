#ifndef THREADS_H
#define THREADS_H

#include <pthread.h>

#include "sync.h"
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int (*Sol)[9];
    int *Row;
    int *Col;
    int *Sub;
    int *Counter;
    int delay;
    int start_row;
    int end_row;
} thread_data;

void create_threads(int Sol[9][9], int Row[10], int Col[10], int Sub[10], int *Counter, int delay);
void *validate_region(void *arg);
void wait_threads(thread_data *data[NUM_THREADS]);

#endif /* THREADS_H */


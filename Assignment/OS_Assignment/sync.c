#include "sync.h"

// Initialize a mutex variable
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Initialize a condition variable 
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


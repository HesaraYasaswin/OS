#ifndef SYNC_H
#define SYNC_H

#include <pthread.h>

extern pthread_mutex_t mutex;
extern pthread_cond_t cond;

#endif /* SYNC_H */

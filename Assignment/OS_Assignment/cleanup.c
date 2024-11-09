#include "cleanup.h"
#include <pthread.h>
#include <stdlib.h>

// Function to perform cleanup of resources used by the threads
void cleanup_threads(thread_data *data[NUM_THREADS]) {    
    for (int i = 0; i < NUM_THREADS; i++)   // Free memory allocated for thread data structures
    {  
        free(data[i]);
    }
}



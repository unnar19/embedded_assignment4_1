#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

pthread_mutex_t sharedVariableMutex;
int32_t gSharedVariable = 0;

void *incrementTask(void *param) {
    while (1) {
        /* Delay for 3 seconds. */
        sleep(3);
        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);
        gSharedVariable++;
        printf("Increment Task: shared var is %d\n", gSharedVariable);
        /* Release the mutex for other task to use. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
}

void *decrementTask(void *param) {
    while (1) {
        /* Delay for 7 seconds. */
        sleep(7);
        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);

        gSharedVariable--;

        printf("Decrement Task: shared var is %d\n", gSharedVariable);
        /* Release the mutex. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
}


int main(void) {
    pthread_t incrementTaskObj, decrementTaskObj;
    /* Create the mutex for accessing the shared variable using the
    * default attributes. */
    pthread_mutex_init(&sharedVariableMutex, NULL);
    /* Create the increment and decrement tasks using the default task
    * attributes. Do not pass in any parameters to the tasks. */
    pthread_create(&incrementTaskObj, NULL, incrementTask, NULL);
    pthread_create(&decrementTaskObj, NULL, decrementTask, NULL);
    /* Allow the tasks to run. */
    pthread_join(incrementTaskObj, NULL);
    pthread_join(decrementTaskObj, NULL);
    return 0;
}

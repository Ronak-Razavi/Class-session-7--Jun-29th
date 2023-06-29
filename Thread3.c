#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

int sharedVariable = 0;  // Shared variable among threads

void *thread(void *arg) {
    for (int i = 0; i < 10000; ++i) {
        sharedVariable++;  // Increment the shared variable
    }
    return NULL;
}

int main() {
    pthread_t tid[NTHREADS];
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_create(&tid[i], NULL, thread, NULL);
    }
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_join(tid[i], NULL);
    }
    printf("Final value of shared variable: %d\n", sharedVariable);

    return 0;
}

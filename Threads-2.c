#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

void *thread(void *arg) {
    printf("Hello from Thread %ld\n", pthread_self());
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
    printf("Main thread returns: %ld\n", pthread_self());

    return 0;
}


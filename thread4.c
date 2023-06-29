#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 1000
int counter=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;

void *thread(void *varg) {
    pthread_mutex_lock(&mutex1);
   counter= counter +1;
   pthread_mutex_unlock(&mutex1);

    return NULL;
}

int main() {
    pthread_t tid[NTHREADS];
    printf ("counter starts at: %d\n",counter);
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_create(&tid[i], NULL, thread, NULL);
    }
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_join(tid[i], NULL);
    }
    printf("Final counter value: %ld\n", counter);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myThread(void *arg) {
    printf("Hello from Thread\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, myThread, NULL);
    pthread_join(tid, NULL);

    return 0;
}
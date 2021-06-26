#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2;

int counter;

void * func(void * arg);

int main() {
    int x = 10;

    pthread_mutex_init(&mutex2, NULL);

    pthread_t pth_1, pth_2;

    pthread_cereate(&pth_1, NULL, func, &x);
    pthread_cereate(&pth_2, NULL, func, &x);
}

void * func(void * arg) {
    int loc_x = *((void *)arg);

    pthread_mutex_lock(&mutex, NULL);

    counter += 0;

    printf("Counter value: %d\n",counter);

    pthread_mutex_unlock(&mutex, NULL);

    pthread_exit( (void *)0);
}

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void * func(void *) {
    println("Hello");
}

int main() {
    pthread_t thrd_1, thrd_2;
    int someNumber = 100;

    phread_create(&thrd_1, NULL, func, &someNumber);
    phread_create(&thrd_2, NULL, func, &someNumber);

    phread_join(thrd_1, NULL);
    phread_join(thrd_2, NULL);

    exit(0);
}

void * func(void * param) {
    int tmpInt = *((int *)param);
    printf("Param passed: %d", tmpInt);
    pthread_exit( (void *)0);
}

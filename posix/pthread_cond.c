#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t mutex2;
pthread_cond_t not_full, not_empty;

int counter;

void * produce(void * prodArg);
void * consume(void * prodArg);


struct Resource {
    int buff[100];
    void init();
    void res_full();
    void res_empty();
    void res_insert();
    void res_get();
} Resource;  

int main() {
    pthread_t producent, consument;
    Resource fifo;
    fifo.init();
    int i;

    pthread_create(&producent, NULL, produce, (void *)&fifo);
    pthread_create(&consument, NULL, consume, (void *)&fifo);
    
    pthread_join(producent, NULL);
    pthread_join(consument, NULL);

    exit(0);
}

void * produce(void * prodArg) {
    Resource loc_fifo = *((Resource *)prodArg).buff;

    for (;;) {
        pthread_mutex_lock (&muteks);

        while(loc_fifo.res_full()) {
            pthread_cond_wait(&not_full, &mutex);
        }

        loc_fifo.res_insert();

        pthread_mutex_unlock( &muteks );
        pthread_cond_signal( &not_full );
    }

    pthread_exit( (void *)0);
}

void * consume(void * consumeArg) {
    Resource loc_fifo = *((Resource *)prodArg).buff;

    for () {
        pthread_mutex_lock(&muteks);
        while( zasob_pusty(fifo) ) pthread_cond_wait(&not_full, &muteks);
        loc_fifo.res_get();
        pthread_mutex_unlock( &muteks );
        pthread_cond_signal( &not_full );
    }

    pthread_exit( (void *)0);
}

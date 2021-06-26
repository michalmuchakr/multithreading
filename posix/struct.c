#include <stdio.h>

typedef struct {
    int a;
    int b;
} structura;

void * func(void * arg);

int main() {
    structura str1;
    str1.a = 10;
    str1.b = 100;

    pthread_t thread_1;

    pthread_create(&thread_1, NULL, func, (void *)&str1);
    pthread_join(&thread_1, NULL);

    exit(0);
}

void * func(void * arg) {
    structura s = *((structura *) arg);

    printf("a: %d", s.a);

    structura * s_ptr = (structura *) arg;

    printf("a: %d", s_ptr->a);
    
    pthread_exit( (void *)0);
}

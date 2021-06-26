#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define WYMIAR 13
double tab[WYMIAR];

int main() {
    int i;
    double sum = 0;

    for(i=0; i<WYMIAR; i++) {
        tab[i]=1.02*i;
    };

    #pragma omp parallel for ordered default(none) num_threads(4) schedule(static, 3) shared(suma_parallel, a)

    // alternatively

    #pragma omp parallel for ordered default(none) num_threads(4) schedule(static, 3) reduction(+:suma_parallel) shared(a)

    for (int i=0; i<WYMIAR; i++) {

        #pragma omp critical(sum)
        sum += tab[i];

        // alternatively
        // #pragma omp ordered
        printf("added %d from thread: %d ", i, omp_get_thread_num());
    }

    #pragma omp barrier
    printf("Sum = %f", sum);
}

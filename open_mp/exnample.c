#include <omp.h>

int main() {
    int lwat;

    printf("max amount of threads: ");
    scanf("%d", &lwat);

    // amount of threads
    omp_set_num_threads(lwat);

    // returns thread number
    omp_get_thread_num();
}
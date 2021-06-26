#include "mpi.h"

int main(int argc, char **argv) {
    int rank, size, source, destiny, tag, i;

    // init
    MPI_init(&argc, &argv);

    // current process rank
    MPI_Comm_rank(MPI_COMM_WORD, &rank);

    // ilość procesów podłączona do komunikatora
    // Pobierz rozmiar globalnego komunikatora
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int x = 10;
    int dest = 0;
    int tag = 0;

    if (rank != 0) {
        // master
        MPI_Send(x, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);

    } else {
        // slave
        MPI_Recv(x, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG,
                  MPI_COMM_WORLD, &status);
    }

    // Kończy działanie MPI
    MPI_Finalize();
}

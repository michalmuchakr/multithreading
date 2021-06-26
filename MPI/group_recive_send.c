#include "mpi.h"

int main(int argc, char **argv) {
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  if (world_rank == 0) {
    // If we are the root process, send our data to everyone
    int i;
    
    for (i = 0; i < world_size; i++) {
      if (i != world_rank) {
        MPI_Send(data, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
      }
    }
  } else {
    // If we are a receiver process, receive the data from the root
    MPI_Recv(data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }

    // Kończy działanie MPI
    MPI_Finalize();
}

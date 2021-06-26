#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

pthread_mutex_t zamek = null;
int sumaGlobal = 0;
pthread_t watki[4] = null;

int *function(void *arg_wsk);

int main() {
  int i = 0;
  int tID = 0;

  pthread_mutex_init(&zamek, NULL);

  for (i = 0; i < 4; i++) {
    tID = i;
    pthread_create(&watki[i], NULL, function, (void *)&(i));
  }

  for (int i = 0; i < 4; i++) {
    pthread_join(watki[i], NULL);
  }

  printf("Wynik to : %d", sumaGlobal);
  pthread_mutex_destroy(&zamek);
}

int *function(void *arg_wsk) {
  int mojeID = *((int *)arg_wsk);
  int sumaLokalna = 0;
  int ratio = 50;
  int i = 0;

  for (i = mojeID * ratio; i < (mojeID * ratio * 2); i++) {
    sumaLokalna += 1560 * i;
  }

  pthread_mutex_lock(&zamek);
  sumaGlobal += sumaLokalna;
  pthread_mutex_unlock(&zamek);

  pthread_exit((void *)0);
}

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main() {
    int pid = fork();
    int wynik;

    if (pid == 0) {
        // proces potomny
        wynik=execv("./program", NULL);

        if(wynik==-1) {
            printf("Proces potomny nie wykonal programu\n");
        }
    } else {
        // proces rodzica
        wait(NULL);
    }
}

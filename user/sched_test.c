#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"




#define NPROC 3
#define NITER 3

int main(int argc, char *argv[]) {
    int priorities[NPROC] = {50, 30, 10};

    for(int i = 0; i < NPROC; i++) {
        int pid = fork();
        if(pid < 0){
            printf("fork failed\n");
            exit(1);
        }

        if(pid == 0){
            // child
            int id = i;
            int prio = priorities[i];

            for(int iter = 0; iter < NITER; iter++){
                // Single printf call per line
                printf("Process %d with priority %d running iteration %d\n", id, prio, iter);
                for(volatile int delay = 0; delay < 1000000; delay++); // optional delay to reduce interleaving
            }
            exit(0);
        }
    }

    // parent waits for all children
    for(int i = 0; i < NPROC; i++){
        wait(0);
    }

    exit(0);
}
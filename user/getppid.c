#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    int pid = getpid();
    int ppid = getppid();   //new_sys_call
    printf("PID: %d, Parent PID: %d\n", pid, ppid);
    exit(0);
}

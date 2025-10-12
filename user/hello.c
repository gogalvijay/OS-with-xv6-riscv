#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("User: calling hello() syscall\n");
  hello();
  printf("User: back from syscall\n");
  exit(0);
}

#include "rand.h"

static unsigned int next = 1;

unsigned int rand(void) {
    next = next * 1103515245 + 12345;
    return (next / 65536) % 32768;
}

void srand(unsigned int seed) {
    next = seed;
}

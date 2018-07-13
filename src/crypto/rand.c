#include <stdio.h>
#include <openssl/rand.h>
#include "rand.h"

typedef union {
    unsigned int uint;
    unsigned char c[sizeof(unsigned int)];
} _rand_uint;

unsigned int rand_uint(unsigned int min, unsigned int max) {
    _rand_uint byte;

    if (!RAND_bytes(byte.c, sizeof(byte.c))) {
        fprintf(stderr, "Can't get random bytes!\n");
        exit(1);
    }

    return byte.uint % (max + 1 - min) + min;
}


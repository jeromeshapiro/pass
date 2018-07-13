#include <stdio.h>
#include <openssl/rand.h>
#include "rand.h"

unsigned int rand_uint(unsigned int min, unsigned int max) {
    unsigned int offset = max - min;

    union {
        unsigned int i;
        unsigned char c[sizeof(unsigned int)];
    } u;

    do {
        if (!RAND_bytes(u.c, sizeof(u.c))) {
            fprintf(stderr, "Can't get random bytes!\n");
            exit(1);
        }
    } while (u.i < (-offset % offset));

    return (u.i % offset) + min;
}


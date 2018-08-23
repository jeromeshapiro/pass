#include <crypto.h>
#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>

#define MIN_SYMBOL 33
#define MAX_SYMBOL 47
#define MIN_UPPER 65
#define MAX_UPPER 90
#define MIN_LOWER 97
#define MAX_LOWER 122

unsigned int seed = 0;

typedef union {
    unsigned int uint;
    unsigned char c[sizeof(unsigned int)];
} _rand;

unsigned int CRYPTO_rand_byte() {
    _rand byte;

    RAND_seed(&seed, sizeof(seed));

    if (!RAND_bytes(byte.c, sizeof(byte.c))) {
        fprintf(stderr, "Can't get random bytes!\n");
        exit(1);
    }

    seed = byte.uint;
    return seed;
}

unsigned int CRYPTO_rand_uint(const unsigned int min, const unsigned int max) {
    seed = CRYPTO_rand_byte();
    return seed % (max + 1 - min) + min;
}

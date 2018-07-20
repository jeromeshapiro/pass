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

unsigned int CRYPTO_rand_uint(const unsigned int min, const unsigned int max) {
    _rand byte;

    RAND_seed(&seed, sizeof(seed));

    if (!RAND_bytes(byte.c, sizeof(byte.c))) {
        fprintf(stderr, "Can't get random bytes!\n");
        exit(1);
    }

    seed = byte.uint;

    return seed % (max + 1 - min) + min;
}

char *CRYPTO_rand_chars(const int len) {
    char *pass = malloc((sizeof(char) * len) + 1);

    int i;

    for (i = 0; i < (len - 1); i++) {
        unsigned int set = CRYPTO_rand_uint(0, 2);
        char c;

        switch(set) {
            case 0:
                c = CRYPTO_rand_uint(MIN_LOWER, MAX_LOWER);
                break;
            case 1:
                c = CRYPTO_rand_uint(MIN_UPPER, MAX_UPPER);
                break;
            case 2:
                c = CRYPTO_rand_uint(MIN_SYMBOL, MAX_SYMBOL);
                break;
        }

        pass[i] = c;
    }

    pass[i] = '\0';

    return pass;
}

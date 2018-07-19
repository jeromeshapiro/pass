#ifndef _CRYPTO_RAND
#define _CRYPTO_RAND

unsigned int CRYPTO_rand_uint(unsigned int min, unsigned int max);
char *CRYPTO_rand_chars(const int len);

#endif // _CRYPTO_RAND


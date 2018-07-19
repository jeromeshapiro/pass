#include <passphrase.h>
#include <crypto.h>
#include <stdlib.h>

#define MIN_RAND_LENGTH 8
#define MAX_RAND_LENGTH 64
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 12

char *PASSPHRASE_new_rand(const short len) {
	return CRYPTO_rand_chars(len);
}

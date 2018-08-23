#include <passphrase.h>
#include <crypto.h>
#include <stdlib.h>
#include <mem.h>

#define MIN_RAND_LENGTH 8
#define MAX_RAND_LENGTH 64
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 12
#define MIN_LOWER_ASCII 97
#define MAX_LOWER_ASCII 122
#define MIN_UPPER_ASCII 65
#define MAX_UPPER_ASCII 90
#define MIN_SYMBOL_ASCII 33
#define MAX_SYMBOL_ASCII 47

enum charsets {
	LOWER_CHARSET = (1 << 0),
	UPPER_CHARSET = (1 << 1),
	SYMBOL_CHARSET = (1 << 2)
};

char *PASSPHRASE_new_rand(const short len) {
	char *buffer = MEM_alloc_buff(sizeof(char) * len);
	int i;

	for (i = 0; i < (len - 1); i++) {
		const unsigned int charset = CRYPTO_rand_uint(0, 2);
		char character;

		switch (charset) {
			case 0:
				buffer[i] = CRYPTO_rand_uint(MIN_LOWER_ASCII, MAX_LOWER_ASCII);
				break;
			case 1:
				buffer[i] = CRYPTO_rand_uint(MIN_UPPER_ASCII, MAX_UPPER_ASCII);
				break;
			case 2:
				buffer[i] = CRYPTO_rand_uint(MIN_SYMBOL_ASCII, MAX_SYMBOL_ASCII);
				break;
		}
	}

	buffer[i] = '\0';

	return buffer;
}

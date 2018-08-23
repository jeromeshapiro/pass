#include <mem.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <crypto.h>

char *MEM_alloc_buff(const int size) {
	char *buff = malloc(size);

	if (buff == NULL) {
		// TODO: handle malloc error
		return NULL;
	}

	if (mlock(buff, size)) {
		// TODO: handle mlock error
		free(buff);
		return NULL;
	}

	return buff;
}

void MEM_free_buff(char *buff, const int size) {
	char *c;

	for (c = buff; *c != '\0'; c++) {
		*c = CRYPTO_rand_byte();
	}

	munlock(buff, size);
	free(buff);
}

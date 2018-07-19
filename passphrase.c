#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cli.h>
#include <storage.h>
#include <crypto.h>

int main(int argc, char **argv) {
	STORAGE_initialize();

	unsigned int r = CRYPTO_rand_uint(0, 1000);

	return CLI_parse(argc, argv);
}

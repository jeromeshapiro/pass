#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cli.h>
#include <storage.h>
#include <crypto.h>

int main(int argc, char **argv) {
	initialize_storage();

	unsigned int r = rand_uint(0, 10);

	return parse_command(argc, argv);
}

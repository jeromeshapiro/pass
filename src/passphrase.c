#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "storage/storage.h"
#include "cli/cli.h"
#include "crypto/rand.h"

int main(int argc, char **argv) {
	initialize_storage();
	return parse_command(argc, argv);
}


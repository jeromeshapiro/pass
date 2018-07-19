#include <stdlib.h>
#include <stdio.h>
#include <cli.h>
#include <storage.h>

int main(int argc, char **argv) {
	STORAGE_initialize();
	return CLI_parse(argc, argv);
}

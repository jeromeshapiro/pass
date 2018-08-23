#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cli.h>
#include <passphrase.h>
#include <mem.h>
#include <storage.h>

#define LS 1431206293
#define CP 1431156757
#define PRINT 800832303
#define CREATE 1568537495
#define UPDATE 1568519047
#define RM 1430910613
#define USER 243105106
#define PASSWORD 2113929183

static const char *help =
"Usage: pass <command>\n"
"    ls                 List all passphrase keys\n"
"    cp                 Copy a passphrase to the clipboard\n"
"    print              Print a passphrase to stdout\n"
"    create             Create a new passphrase\n"
"    update             Update an existing passphrase\n"
"    rm                 Delete a passphrase\n"
"\nOptions:\n"
"    -h, --help         Show this screen.\n"
"    -v, --version      Show verion.\n"
"\n";

static const int _hash(char const *input) { 
	const int ret_size = 32;
	size_t ret = 0x555555;
	const int per_char = 7;

	while (*input) { 
		ret ^= *input++;
		ret = (ret << per_char) | (ret >> (ret_size - per_char));
	}

	return ret;
}

static void _print_usage() {
	printf("%s", help);
}

// List all passphrase keys
static int _list_passphrases() {
	printf("list passwords\n");
	return 0;
}

// Copy a passphrase to the clipboard
static int _copy_passphrase() {
	printf("copy password to clipboard\n");
	return 0;
}

// Print a passphrase to stdout
static int _print_passphrase() {
	printf("print password to stdout\n");
	return 0;
}

// Create a new passphrase
static int _create_passphrase(char *key, int length) {
	char *passphrase = PASSPHRASE_new_rand(length);

	STORAGE_save_passphrase(key, passphrase);

	MEM_free_buff(passphrase, sizeof(passphrase));

	return 0;
}

static int _update_user() {
	printf("update user\n");
	return 0;
}

// Update an existing passphrase
static int _update_password() {
	printf("update password\n");
	return 0;
}

// Delete a passphrase
static int _remove_password() {
	printf("remove password\n");
	return 0;
}

int CLI_parse(int argc, char **argv) {
	if (!argv[1]) {
		_print_usage();
		return 0;
	}

	switch(_hash(argv[1])) {
		case LS:
			return _list_passphrases();
			break;
		case CP:
			return _copy_passphrase();
			break;
		case PRINT:
			return _print_passphrase();
			break;
		case CREATE:
			// Must specify passphrase key
			if (!argv[2]) {
				_print_usage();
				return 0;
			}

			return _create_passphrase(argv[2], 24);
			break;
		case UPDATE:
			if (!argv[2]){
				_print_usage();
				return 0;
			}

			switch (_hash(argv[2])) {
				case USER:
					return _update_user();
					break;
				case PASSWORD:
					return _update_password();
					break;
				default:
					printf("unrecognised update command!\n");
					return 1;
					break;
			}
			break;
		case RM:
			return _remove_password();
			break;
		default:
			printf("unrecognized command!\n");
			return 1;
			break;
	}
}

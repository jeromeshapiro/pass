#include <stdio.h>
#include <cli.h>

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

int parse_command(int argc, char **argv) {
	char *key = argv[2];

	if (!argv[1]) {
		_print_usage();
		return 0;
	}

	switch(_hash(argv[1])) {
		case LS:
			printf("list passwords\n");
			break;
		case CP:
			printf("copy password to clipboard\n");
			break;
		case PRINT:
			printf("print password to stdout\n");
			break;
		case CREATE:
			printf("create new password\n");
			break;
		case UPDATE:
			if (!argv[2]) {
				_print_usage();
				return 1;
			}

			key = argv[3];

			switch (_hash(argv[2])) {
				case USER:
					printf("update user\n");
					break;
				case PASSWORD:
					printf("update password\n");
					break;
				default:
					printf("unrecognised update command!\n");
					return 1;
					break;
			}

			break;
		case RM:
			printf("remove password\n");
			break;
		default:
			printf("unrecognized command!\n");
			break;
	}

	return 0;
}


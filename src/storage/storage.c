#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define HOME_DIR "/home/"
#define CONFIG_DIR "/.pass"

static struct stat st = {0};
static FILE *auth;
static FILE *passwords;

void initialize_storage() {
	char *username = getenv("USER");
	char *config_path = malloc(strlen(HOME_DIR) + strlen(username) + strlen(CONFIG_DIR) + 1);
	strcpy(config_path, HOME_DIR);
    strcat(config_path, username);
	strcat(config_path, CONFIG_DIR);

	const int dir_status = stat(config_path, &st);

	if (dir_status == -1) {
		mkdir(config_path, 0700);
	}

	free(config_path);
}

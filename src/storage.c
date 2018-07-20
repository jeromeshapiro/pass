#include <storage.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>

#define CONFIG_DIR_NAME "/.pass"

static struct stat st = {0};
static char *config_path;
static FILE *auth;
static FILE *passwords;

char *_get_home_dir_path()
{
	struct passwd *user;
	uid_t uid;

	uid = geteuid();
	user = getpwuid(uid);

	return user->pw_dir;
}

void STORAGE_initialize()
{
	// Create storage directory if not exists
	char *home_dir_path = _get_home_dir_path();
	
	config_path = malloc(strlen(home_dir_path) + strlen(CONFIG_DIR_NAME) + 1);

	strcpy(config_path, home_dir_path);
	strcat(config_path, CONFIG_DIR_NAME);

	const int dir_missing = stat(config_path, &st) == -1;

	if (dir_missing == -1) {
		mkdir(config_path, 0700);
	}


}

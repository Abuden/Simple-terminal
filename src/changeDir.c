#include "shell.h"



void changeDir(char **input, int count) {
	if (count == 1) {
		chdir(getenv("HOME"));
	} else {
		if (chdir(input[1]) != 0)
			perror("cd");
	}
}

bool isCD(char *cmd) {
	if (strcmp(cmd, "cd") == 0)
		return true;

	return false;
}
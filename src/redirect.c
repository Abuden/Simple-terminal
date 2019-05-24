#include "shell.h"

void redirect(char **input, int count) {
	char *filename = input[count-1];
	int file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	int ret;

	if (file < 0) {
		perror("open");
		exit(1);
	}
	
	ret = dup2(file, 1);

	if (ret < 0) {
		perror("dup2");
		exit(1);
	}

	close(file);
}

bool containsRedirect(char **input, int count) {
	for (int i=0; i<count; i++) {
		if (strcmp(input[i], ">") == 0) {
			return true;
		}
	}

	return false;
}

int getIndexOfRedirect(char **input, int count) {
	int index;
	
	for (int i=0; i<count; i++) {
		if (strcmp(input[i], ">") == 0) 
			index =  i;
	}

	return index;
}
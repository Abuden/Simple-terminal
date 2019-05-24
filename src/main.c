#include "shell.h"

int main(int argc, char *argv[]) {
	char *line = (char*) malloc(sizeof(char) * 32);
	size_t len = 0;
	char **input = malloc(sizeof(char *));
	int count = 0;

	signal(SIGINT, sig_handler);
	prompt();
	signal(SIGINT, sig_handler);
	
	while (getline(&line, &len, stdin) != -1) {	
			line[strcspn(line, "#\n")] = 0;
			char *temp = strtok(line, " ");
			
			while (temp != NULL) {
				input[count] = temp;
				count++;
				input = realloc(input, (count + 1) * sizeof(char *));
				temp = strtok(NULL, " ");
			}
		
			printf("\n");
			if (isCD(input[0]))
				changeDir(input, count);
			else
				runCommand(input, count);
		
		free(input);
		input = malloc(sizeof(char *));
		count = 0;
		prompt();
	}

	exitProgram();
}
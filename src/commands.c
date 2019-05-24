#include "shell.h"

void runCommand(char **input, int count) {
	char *cmd = input[0];
	
	if (isCommand(cmd)) {		
		char *argv[count];
		int child_status;

		if (containsRedirect(input, count)) {
			int index = getIndexOfRedirect(input, count);
			for (int i=0; i<index; i++)
				argv[i] = input[i];
				
			argv[index] = NULL;
			
		} else {
			for (int i=0; i<count; i++)
				argv[i] = input[i];

			argv[count] = NULL;
		}
		
		pid_t child_pid = fork();
		
		if (child_pid == 0) {
			printf("\n");
			if (containsRedirect(input, count)) 
				redirect(input, count);
			execvp(cmd, argv);
		} else {
			signal(SIGINT, sig_handler);
			wait(&child_status);
			signal(SIGINT, sig_handler);
		}
	} else 
		printf("Invalid command, please try again\n");
}

bool isCommand(char *cmd) {
	const char *commands[8] = {"ls", "pwd", "echo", "sleep", "whoami", "cat", "mkdir", "rmdir"};

	for (int i=0; i<8; i++) {
		if (strcmp(cmd, commands[i]) == 0)
			return true;
	}
	
	return false;
}
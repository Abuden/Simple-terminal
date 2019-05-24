#include "shell.h"

void sig_handler(int signo) {
	signal(signo, sig_handler);
	printf("\n");
	prompt();
	fflush(stdout);
}


#include "shell.h"

void prompt() {
	char buffer[100];
    time_t now = time(0);
    strftime(buffer, 100, "%d/%m | %X", localtime(&now));
    printf("\n[%s] # ", buffer);
}
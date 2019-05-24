#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <signal.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PROGRAM_NAME "shell"
#define AUTHOR "Braddy Yeoh"
#define STUDENT_NUMBER 17357376
#define EMAIL "braddy.yeoh@ucdconnect.ie"
#define VERSION 1.0

#define MAX_PATH 1000

void runCommand(char **input, int count);
bool isCommand(char *cmd);
bool isCD(char *cmd);
void prompt();
void exitProgram();
void sig_handler(int signo);
void redirect(char **input, int count);
bool containsRedirect(char **input, int count);
int getIndexOfRedirect(char **input, int count);
void changeDir(char **input, int count);

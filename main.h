#ifndef MAIN_H
#define MAIN_H

/* Global */
extern char **environ;

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Function prototypes*/
char **tokenizer(char *str, const char *delimiter);
void execute(char **args);
int check_builtin(char **args);
void print_env(void);

#endif

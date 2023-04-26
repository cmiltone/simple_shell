#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

#ifdef _WIN32
  #define ON_WIN 1
#else
  #define ON_WIN 0
#endif

void shell(char *filename);
void exec_command(char *args[], char *filename);
char **prompt();
size_t str_len(char *s);
int str_cmp(char *a, char *b);
int str_contains(char *a, char *b);
char *get_env(char *e);
char **get_path_cmds();
char *get_command_in_path(char *cmd);
char *str_cat(char *a, char *b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void ctrl_c(int sig);

#endif

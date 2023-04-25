#ifndef MAIN_H
#define MAIN_H

#define BUFFSIZE 1024

/*
 * struct info_s - struct that contains potential argumnts for commands
 * @argv: Null-terminated array of strings containing arguments
 * passed to the command
 * @env: Null-terminated array of strings containing environment varibales.
 * @status: Exit status of the last command executed
 * @err_num: Integer value to represent error numbers
 */

typedef struct info_s
{
	char **argv;
	char **env;
	int status;
	int err_num;
} info_t;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


void shell(char *args[], char *filename);
char **prompt();
char *teamstrncpy(char *dest, char *src, size_t n);
char *teamstrncat(char *dest, char *src, int n);
char *teamstrchr(char *s, char c);
size_t _strlen(char *s);
int _erratoi(char *new_str);
int teamexit(info_t *info);
int _eputchar(char new_char);
void _eputs(char *new_str);
void print_error(info_t *info, char *new_msg);
int execute_command(info_t *info);
char *read_line(int *should_free);

#endif

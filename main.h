#ifndef MAIN_H
#define MAIN_H

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
/* Exit functions*/
char *teamstrncpy(char *dest, char *src, size_t n);
char *teamstrncat(char *dest, char *src, int n);
char *teamstrchr(char *s, char c);
size_t _strlen(char *s);

#endif

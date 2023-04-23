#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


void shell(char *args[], char* filename);
char **prompt();
int str_len(char *s);
int str_cmp(char * a, char *b);

#endif

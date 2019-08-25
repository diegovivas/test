#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int _printstring(char *s);
int _printf(const char *format, ...);
int print_number(int n);
int _putchar(char c);
char quitarsalto(char *linea);
int _free(char **token, int tam);
#endif



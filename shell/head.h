#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int count_args(char **args);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
int tamanio(char *linea);
char quitarsalto(char *linea);
int comparar(char *linea);
int numerotokens(char *linea, char *separador);
char **funciontok(char *linea, char *separador);
char **concadenar(char **tokens, int numtokens, char *comando);
char *concadenar2(char *dest, char *token, char *comando);
int search_env(char **env, char **argv);

typedef struct args
{
        char * args;
        struct args * next;
} list_t;

#endif

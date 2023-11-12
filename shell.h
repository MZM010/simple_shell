#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
int roulete(char **argument, int i, int *status);
void please_print_me(char *str);
void check_exit(char **command, int *status);
void perror_exit_failure();
void check_isatty();
char *read_command(void);
char **split_command(char *command);
char *get_path(char *command);
int extractExitStatus(int status);
void check_command(char **argument, int *status);
void free_arguments(char **argument);
void write_error(char *programme);
void check_env(void);


#endif
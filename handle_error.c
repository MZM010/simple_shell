#include "shell.h"



void perror_exit_failure()
{
    perror("execve");
    exit(EXIT_FAILURE);
}
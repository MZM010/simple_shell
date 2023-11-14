#include "shell.h"
/**
 * perror_exit_failure - print error
 */
void perror_exit_failure(void)
{
	perror("execve");
	exit(EXIT_FAILURE);
}

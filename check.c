#include "shell.h"

/**
 * check_isatty - function checks if the standard input is associated
 * with a terminal
 *
 * Return: Nothing.
 */
void check_isatty(void)
{
	if (isatty(STDIN_FILENO))
	{
		please_print_me("$ ");
	}
}

/**
 * check_exit - function is responsible for freeing some memory
 * and exit
 * @command: pointer to a pointer to a character array
 * @status: pointer to an integer
 * Return: Nothing.
 */
void check_exit(char **command, int *status)
{
	free_arguments(command);
	exit(*status);
}

/**
 * check_env - function is responsible for env
 *
 * Return: Nothing.
 */
void check_env(void)
{
	int counter;

	for (counter  = 0; environ[counter] != NULL; counter++)
	{
		please_print_me(environ[counter]);
		please_print_me("\n");
	}
}


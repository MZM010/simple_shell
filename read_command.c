#include "shell.h"

/**
 * read_command - function that read the command
 *
 * Return: Nothing.
 */
char *read_command(void)
{
	char *argument_line = NULL;
	size_t length = 0;
	int bytes_of_argument;

	check_isatty();
	bytes_of_argument = getline(&argument_line, &length, stdin);
	if (bytes_of_argument == -1)
	{
		free(argument_line);
		return (NULL);
	}
	return (argument_line);
}

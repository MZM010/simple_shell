#include "shell.h"
/**
 * check_command - check if command is there
 * @argument: use argument
 * @status: check status
 */
void check_command(char **argument, int *status)
{
	char *command;
	pid_t the_process;
	int i = 0;
	int the_return_value;

	the_return_value = roulete(argument, i, status);
	if (the_return_value == 3)
	{
		command = get_path(argument[0]);
		if (!command)
		{
			write_error(argument[0]);
			*status = 127;
			return;
		}
		the_process = fork();
		if (the_process == 0)
		{
			if (execve(command, argument, environ) == -1)
			{
				perror_exit_failure();
			}
		}
		else
		{
			wait(status);
			if (WIFEXITED(*status))
			{
				*status = (extractExitStatus(*status));
			}
			free(command);
		}
	}

}

/**
 * free_arguments - free arguments
 * @argument: the argument
 */
void free_arguments(char **argument)
{
	int i = 0;

	if (argument == NULL)
	{
		return;
	}

	while (argument[i] != NULL)
	{
		free(argument[i]);
		i++;
	}
	free(argument);
}
/**
 * write_error - write the error
 * @programme: the programme needed to occurs the error for it
 */
void write_error(char *programme)
{
	write(STDERR_FILENO, "./hsh: line 1: ", 15);
	write(STDERR_FILENO, programme, strlen(programme));
	write(STDERR_FILENO, ": command not found\n", 20);
}
/**
 * roulete - check roulete
 * @argument: the argument need to be in
 * @status: the status that will be stored
 * @i: just an i
 * Return: return a certain value
 */
int roulete(char **argument, int i, int *status)
{
	char *commands[] = {"cmd", "env", "exit", "set", "unset"};

	for (i = 0; i < 3; i++)
	{
		if (strcmp(argument[0], commands[i]) == 0)
		{
			switch (i)
			{
				case 0:
					printf("cmd\n");
					break;
				case 1:
					printf("env\n");
					break;
				case 2:
					check_exit(argument, status);
					break;
			}
			break;
		}
	}
	return (i);

}

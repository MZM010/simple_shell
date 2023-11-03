#include "shell.h"

/**
* check_command - checking the user's input command
* @argument: pointer array of strings
* @status: int pointer
* Return: Nothing.
*/
void check_command(char **argument, int *status)
{
char *command = get_path(argument[0]);
pid_t the_process;
int i = 0;

if (strcmp(argument[0], "cmd") == 0)
printf("cmd\n");
else if (strcmp(argument[0], "env") == 0)
printf("env\n");
else if (strcmp(argument[0], "exit"))
check_exit(argument, status);
else
{
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
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(status);
if (WIFEXITED(*status))
{
*status = (WEXITSTATUS(*status));
}
free(command);
}
}

}

/**
* free_arguments - unction is responsible for freeing memory associated with
* the argument array
* @argument: pointer array of strings
* Return: Noting.
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
* write_error - function is used to print an error message to
* the standard error
* @programme: char pointer
* Return: Nothing.
*/
void write_error(char *programme)
{
write(STDERR_FILENO, "./hsh: line 1: ", 15);
write(STDERR_FILENO, programme, strlen(programme));
write(STDERR_FILENO, ": command not found\n", 20);
}

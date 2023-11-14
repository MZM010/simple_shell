#include "shell.h"
/**
 * check_directory - check the directory
 * @dir: the dir
 * @command: the command for all
 *Return: the value needed
 */
char *check_directory(const char *dir, const char *command)
{
	char command_path[2048];

	strcpy(command_path, dir);
	strcat(command_path, "/");
	strcat(command_path, command);

	if (access(command_path, 0) == 0 && access(command_path, 1) == 0)
	{
		return (strdup(command_path));
	}

	return (NULL);
}
/**
 * get_path - this function is get the path
 * @command: the command
 * Return: the path
 */
char *get_path(char *command)
{
	char *path, *dir, *path_copy, *result;

	if (access(command, 0) == 0 && access(command, 1) == 0)
	{
		return (strdup(command));
	}

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		result = check_directory(dir, command);
		if (result != NULL)
		{
			free(path_copy);
			return (result);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

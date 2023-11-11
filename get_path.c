#include "shell.h"

char *get_path(char *command)
{
	char *path;
	char *dir;
	char *path_copy;
	char command_path[2048];
	/* Copy of the command*/
    if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
    {
		return (strdup(command)); /* Return the full path */
	}

	path = getenv("PATH");
    if (!path)
    {
        return NULL;
    }
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		strcpy(command_path, dir);
		strcat(command_path, "/");
		strcat(command_path, command);

		if (access(command_path, F_OK) == 0 && access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(command_path)); /* Return the full path */
		}

		dir = strtok(NULL, ":"); /* Proceed to the next directory*/
	}

	free(path_copy);
	return (NULL);
}
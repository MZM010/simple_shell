#include "shell.h"
/**
 * extractExitStatus - extract the exit status
 * @status: status
 * Return: each value
 */
int extractExitStatus(int status)
{
	if (WIFEXITED(status))
	{
		return ((status >> 8) & 0xFF);
	}
	else
	{
		return (-1);
	}
}

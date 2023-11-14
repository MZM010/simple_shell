#include "shell.h"
/**
 * please_print_me - print the code
 * @str: the string
 */
void please_print_me(char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

#include "shell.h"

void please_print_me(char *str)
{
    write(STDOUT_FILENO,str, strlen(str));
}
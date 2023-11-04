#include "shell.h"


int main()
{
    char *the_command = NULL,**another_one = NULL;
    int status = 0;
    bool x = true;
    
    while (x)
    {
        the_command = read_command();
        if (!the_command)
            break;
        another_one = split_command(the_command);
        if (another_one[0] == NULL)
        {
            free_arguments(another_one);
            continue;
        }
        check_command(another_one, &status);
        free_arguments(another_one);

    }
    return (status);
}
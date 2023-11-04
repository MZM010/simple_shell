
#include "shell.h"

int extractExitStatus(int status)
{
    if (WIFEXITED(status)) {
        return (status >> 8) & 0xFF;
    }
    else
    {
        return (-1);
    }
}
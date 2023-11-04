#include "shell.h"


char **split_command(char *command) {
    char **big_one = NULL, *tmp = NULL, *token = NULL;
    int i, j;

    j = i = 0;
    if (!command) {
        return NULL;
    }
    tmp = strdup(command);
    token = strtok(tmp, " \n\t");
    while (token != NULL) {
        j++;
        token = strtok(NULL, " \n\t");
    }

    free(tmp);

    big_one = (char **)malloc(sizeof(char *) * (j + 1));
    if (big_one == NULL){
        free(command);
        return NULL;
    }

    tmp = strdup(command);
    token = strtok(tmp, " \n\t");
    while (token != NULL) {
        big_one[i] = strdup(token);
        token = strtok(NULL, " \n\t");
        i++;
    }
    big_one[i] = NULL;
    free(tmp);
    free(command);

    return big_one;
}

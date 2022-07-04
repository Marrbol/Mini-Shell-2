/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** cat_command
*/

#include "my.h"
#include "mysh.h"

char **cat_command(char *command, char **path)
{
    int i = 0;

    path[0] += 5;
    while (path[i] != NULL) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], command);
        i++;
    }
    return path;
}

/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** verif_access
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

int verif_access(char **path)
{
    for (int i = 0; path[i] != NULL; i++) {
        if (access(path[i], X_OK) == 0)
            return i;
    }
    return -1;
}

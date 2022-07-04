/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** dup_env
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>

char **dup_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    char **env_dup = malloc(sizeof(char *) * (i + 1));

    for (i = 0; env[i] != NULL; i++)
        env_dup[i] = my_strcpy_m(env[i], my_strlen(env[i]));
    env_dup[i] = NULL;
    return env_dup;
}

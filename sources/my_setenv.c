/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** my_setenv
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <string.h>

static void my_free_setenv(char **old_env)
{
    for (size_t i = 0; old_env[i]; i++)
        free(old_env[i]);
    free(old_env);
}

char **my_setenv(char **old_env, char *name, char *content)
{
    size_t size_old_env = array_size(old_env);
    size_t index = 0;
    char **new_env = NULL;
    char *new_variable = NULL;
    if (!name) {
        print_env(old_env);
        return old_env;
    }
    new_env = malloc(sizeof(char *) * (size_old_env + 2));
    for (; old_env[index] != NULL; index++)
        new_env[index] = my_strcpy_m(old_env[index],
                                    my_strlen(old_env[index]));
    new_variable = my_strcat(name, "=");
    if (content)
        new_variable = my_strcat(new_variable, content);
    new_env[index] = my_strdup(new_variable);
    new_env[index + 1] = NULL;
    my_free_setenv(old_env);
    return new_env;
}

static size_t my_get_env_line_index(char **env, char *line)
{
    size_t i = 0;
    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], line, my_strlen(line)))
            return i;
    }
    return i + 1000;
}

char **my_unsetenv(char **env, char *line)
{
    char **new_env = malloc(sizeof(char *) * array_size(env));
    size_t counter = 0;
    size_t index_line = my_get_env_line_index(env, line);
    if (index_line > array_size(env))
        return env;
    for (size_t i = 0; env[i]; i++)
        if (i != index_line) {
            new_env[counter] = my_strdup(env[i]);
            counter++;
        }
    for (size_t i = 0; env[i]; i++)
        free(env[i]);
    free(env);
    new_env[counter] = NULL;
    return new_env;
}

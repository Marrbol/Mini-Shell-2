/*
** EPITECH PROJECT, 2022
** minishell 2
** File description:
** mi shell II le retour
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "mysh.h"

void select_option3(char ***env, char **buffer)
{
    if (my_strncmp(buffer[0], "unsetenv", 8))
        *(env) = my_unsetenv(*(env), buffer[1]);
    else {
        exec((*env), buffer);
    }
}

void select_option2(char ***env, char **buffer)
{
    if (my_strncmp(buffer[0], "E", 2))
        my_printf("Salut Eliott, met moi 4444 à ma review stp\n");
    else if (my_strncmp(buffer[0], "cd", 3))
        my_cd(*(env), buffer);
    else
        select_option3(env, buffer);
}

void select_option(char ***env, char **buffer)
{
    if (my_strncmp(buffer[0], "setenv", 7))
        *(env) = my_setenv(*(env), buffer[1], buffer[2]);
    else if (my_strncmp(buffer[0], "env", 4))
        print_env(*(env));
    else
        select_option2(env, buffer);
}

static bool mishell(char **env)
{
    char *buffer = NULL;
    size_t index_separator = 0;

    while (1) {
        if (isatty(0) == 1)
            my_putstr("$>");
        if ((buffer = getline_and_parse()) == NULL)
            break;
        for (size_t exe_command = get_nb_command(buffer); exe_command > 0;
                exe_command--) {
            index_separator = execute_line(buffer, &env);
            buffer += index_separator + 1;
        }
    }
    return true;
}

int main(__attribute__((unused))int ac, __attribute__((unused))char **av,
char **env)
{
    char **env_dup = dup_env(env);

    if (mishell(env_dup) == false)
        return 0;
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** print_env
*/

#include "my.h"
#include "mysh.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
}

/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** choose_redirection
*/

#include "my.h"
#include "mysh.h"

bool check_double_redirection(char *buffer)
{
    for (size_t i = 0; buffer[i]; i++)
        if (buffer[i] == '>' && buffer[i + 1] == '>')
            return true;
    return false;
}

int choose_redirection(char *buffer, char **env, int index_separator)
{
    if (check_double_redirection(buffer)) {
        redirection(buffer, env, false);
        return index_separator;
    }
    redirection(buffer, env, true);
    return index_separator;
}

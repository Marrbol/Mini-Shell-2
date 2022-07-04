/*
** EPITECH PROJECT, 2022
** B-PSU-210-REN-2-1-minishell2-martin.boucault
** File description:
** check_pipe
*/

#include "my.h"
#include "mysh.h"

bool check_pipe(char *current_comand)
{
    for (size_t i = 0; current_comand[i]; i++)
        if (current_comand[i] == '|')
            return true;
    return false;
}

bool check_double_pipe(char *current_line)
{
    size_t counter_pipe = 0;

    for (size_t i = 0; current_line[i] != '\0'; i++)
        if (current_line[i] == '|')
            counter_pipe++;
    if (counter_pipe >= 2)
        return true;
    return false;
}

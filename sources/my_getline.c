/*
** EPITECH PROJECT, 2022
** B-PSU-101-REN-1-1-minishell1-martin.boucault
** File description:
** my_getline
*/

#include "my.h"
#include "mysh.h"
#include <stdio.h>

size_t my_getline(char **buffer)
{
    size_t len = 0;

    if (getline(buffer, &len, stdin) == -1 || len == 0)
        return 0;
    buffer[len - 1] = '\0';
    return len;
}

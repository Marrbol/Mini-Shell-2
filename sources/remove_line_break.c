/*
** EPITECH PROJECT, 2022
** wait_repo
** File description:
** remove_line_break
*/

#include "my.h"
#include "mysh.h"

char *remove_line_break(char *str)
{
    int i = 0;

    for (; str[i] != '\n'; i++);
    str[i] = '\0';
    return str;
}

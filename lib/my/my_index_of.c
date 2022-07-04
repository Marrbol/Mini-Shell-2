/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** my_index_of
*/
#include <stdio.h>
#include "my.h"

int my_index_of(char *str, char c)
{
    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}

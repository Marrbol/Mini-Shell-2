/*
** EPITECH PROJECT, 2021
** str len
** File description:
** on va donner la len d uhne str
*/

#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** my_stcpy_m
*/

#include "my.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcpy_m(char const *str, unsigned int n)
{
    char *res = malloc(sizeof(char) * (n + 2));

    my_strncpy(res, str, n);
    return res;
}

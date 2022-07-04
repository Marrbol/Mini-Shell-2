/*
** EPITECH PROJECT, 2021
** str cat
** File description:
** on cat une str
*/
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int lensrc = my_strlen(src);
    int lendest = my_strlen(dest);
    char *res = malloc(sizeof(char) * (lendest + lensrc + 1));
    int i = 0;

    if (lensrc == 0 || lendest == 0)
        return NULL;
    for (; i != lendest; i++)
        res[i] = dest[i];
    for (int k = 0; i != (lensrc + lendest); i++, k++)
        res[i] = src[k];
    res[i] = '\0';
    return res;
}

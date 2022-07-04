/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** on copy une str
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strcpy (char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        dest[i + 1] = '\0';
        i++;
    }
    return dest;
}

char *my_strncpy (char *dest, char const *src, unsigned int n)
{
    unsigned int i = 0;

    if (src == NULL)
        return NULL;
    while (src[i] != '\0' && i != n) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
        i++;
    }
    return dest;
}

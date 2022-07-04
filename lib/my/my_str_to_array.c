/*
** EPITECH PROJECT, 2021
** my_str_to_char **.c
** File description:
** from str to char **
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int size_array(char *str, char delim)
{
    int i = 0;
    int cunter = 1;

    while (str[i] != '\0') {
        if (str[i] == delim) {
            cunter++;
        }
        i++;
    }
    if (cunter == 1)
        return 2;
    return cunter;
}

char **my_str_to_array(char *str, char delim)
{
    char **result = malloc(sizeof(char *) * (size_array(str, delim) + 1));
    int at = 0;
    unsigned int i = 0;

    str = my_cleanstr(str);
    if (str == NULL || result == NULL)
        return NULL;
    while (*str != '\0') {
        at = my_index_of(str, delim);
        if (at == -1 || at == 0) {
            result[i++] = my_strdup(str);
            break;
        }
        result[i++] = my_strcpy_m(str, at);
        str += at + 1;
    }
    result[i] = NULL;
    return result;
}

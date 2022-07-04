/*
** EPITECH PROJECT, 2021
** str cmmp
** File description:
** on compare des str et on return un nombre
*/

#include <unistd.h>
#include "my.h"
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int count = 0 ;
    int i = 0;
    int minlen = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return -1;
    if (my_strlen(s1) >= my_strlen(s2))
        minlen = my_strlen(s2);
    else
        minlen = my_strlen(s1);
    while (i != minlen) {
        if (s1[i] != s2[i])
            count = count + (s1[i] - s2[i]);
        i++ ;
    }
    return count;
}

bool my_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    while (i <= n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return false;
        i++ ;
    }
    return true;
}

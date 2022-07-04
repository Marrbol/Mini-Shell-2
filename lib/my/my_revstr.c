/*
** EPITECH PROJECT, 2021
** my.revstr
** File description:
** revstr
*/
#include <stdio.h>
#include <stdlib.h>

char *my_revstr(char *str)
{
    int len = 0;
    int i = 0;
    char *rev;
    int j = 0;

    while (str[len] != '\0') {
        len++;
    }
    i = len - 1;
    rev = malloc(sizeof(char) * (i + 1));

    while (j <= i) {
        while (i >= 0) {
            rev[j] = str[i];
            i--;
            j++;
        }
    }
    return rev;
}

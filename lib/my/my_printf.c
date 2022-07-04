/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const struct_flags tab[] = {
    {'f', &pfloat},
    {'b', &pbin},
    {'i', &pnbr},
    {'d', &pnbr},
    {'X', &phexa},
    {'o', &poct},
    {'x', &pshexa},
    {'c', &pchar},
    {'s', &pstr},
    {'%', &percent},
    {'\0', NULL},
};

static int check_args(char c, int i, va_list args)
{
    switch (c) {
    case 'f':
        my_put_float(va_arg(args, double), i);
        break;
    default:
        break;
    }
    return 0;
}

static void check_format(char *str, int i, va_list args)
{
    int tmp = 0;
    char c;

    if (str[i + 2] >= '0' && str[i + 2] <= '9') {
        tmp = str[i + 2] - 48;
        c = str[i + 3];
        check_args(c, tmp, args);
    }
}

static void get_flags(char *str, int i, va_list args)
{
    for (int j = 0; tab[j].flags != '\0'; j++) {
        if (str[i + 1] == tab[j].flags) {
            tab[j].ptr(args);
        } else if (str[i + 1] == '.') {
            check_format(str, i, args);
            i += 4;
        }
    }
}

void check_point(char *str, int i)
{
    if (str[i + 1] == '.') {
        i += 2;
    }
}

int my_printf(char *str, ...)
{
    va_list args;
    va_start (args, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            get_flags(str, i, args);
            check_point(str, i);
            i = i + 1;
        } else
            my_putchar(str[i]);
    }
    return 0;
}

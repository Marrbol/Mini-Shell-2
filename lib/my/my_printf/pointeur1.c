/*
** EPITECH PROJECT, 2022
** B-PSU-100-REN-1-1-myprintf-martin.boucault
** File description:
** pointeur1
*/

#include "my.h"
#include <stdarg.h>

void pchar(va_list args)
{
    my_putchar(va_arg(args, int));
}

void pstr(va_list args)
{
    my_putstr(va_arg(args, char *));
}

void pfloat(va_list args)
{
    my_put_float2(va_arg(args, double));
}

void pbin(va_list args)
{
    my_put_nbr(dec_to_binaire(va_arg(args, int)));
}

void pnbr(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

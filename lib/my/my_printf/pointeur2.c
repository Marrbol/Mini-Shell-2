/*
** EPITECH PROJECT, 2022
** B-PSU-100-REN-1-1-myprintf-martin.boucault
** File description:
** pointeur2
*/

#include "my.h"
#include <stdarg.h>

void phexa(va_list args)
{
    my_dec_to_hexa(va_arg(args, int));
}

void poct(va_list args)
{
    my_dec_to_octal(va_arg(args, int));
}

void pshexa(va_list args)
{
    my_dec_to_small_hexa(va_arg(args, int));
}

void percent(__attribute__((unused))va_list args)
{
    my_putchar('%');
}

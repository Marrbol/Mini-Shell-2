/*
** EPITECH PROJECT, 2021
** MY_PUT_FLOAT
** File description:
** This
*/

#include "my.h"

void my_put_float2(float nb)
{
    int i = nb * 100;

    my_put_nbr(i / 100);
    my_putchar('.');
    my_put_nbr((i % 100) / 10);
    my_put_nbr((i % 100) % 10);
}

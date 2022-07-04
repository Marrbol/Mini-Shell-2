/*
** EPITECH PROJECT, 2021
** MY_PUT_FLOAT
** File description:
** putfloat
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

void my_put_float(float nb, int n)
{

    int p = my_compute_power_it(10, n);
    int q = my_compute_power_it(10, n - 1);
    int i = nb * p;
    if (n == 0) {
        my_put_nbr((int) nb);
        return;
    }
    my_put_nbr(i / p);
    my_putchar('.');
    my_put_nbr((i % p) / q);
    my_put_nbr((i % p) % q);
}

/*
** EPITECH PROJECT, 2021
** my_compute power it
** File description:
** on fais des puissances en it
*/

#include <stdio.h>

int my_compute_power_it(int nb, int p)
{
    int tmp = 0;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return (1);
    }
    tmp = nb;
    while (p > 1) {
        nb = tmp * nb;
        p = p - 1;
    }

    return nb;
}

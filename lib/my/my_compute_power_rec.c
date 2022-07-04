/*
** EPITECH PROJECT, 2021
** my compute power rec
** File description:
** une fonction power en recursive
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }

    return (nb * my_compute_power_rec(nb, (p -1)));
}

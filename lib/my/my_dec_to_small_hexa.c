/*
** EPITECH PROJECT, 2021
** my_dec_to_small_hex
** File description:
** ta compris
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_dec_to_small_hexa(int nbr)
{
    int hex = 0;

    if (nbr >= 2) {
        hex = nbr % 16;
        nbr = nbr / 16;
        my_dec_to_small_hexa(nbr);
    } else if (nbr > 0) {
        hex = nbr % 16;
        nbr = nbr / 16;
    }
    if (hex > 9) {
        my_putchar(hex + 87);
    } else
        my_put_nbr(hex);
    return nbr;
}

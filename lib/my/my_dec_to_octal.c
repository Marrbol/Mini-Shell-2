/*
** EPITECH PROJECT, 2021
** my_dec_to_octal
** File description:
** ta deja compris
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_dec_to_octal(int nbr)
{
    int oct = 0;

    if (nbr >= 2) {
        oct = nbr % 8;
        nbr = nbr / 8;
        my_dec_to_octal(nbr);
    } else if (nbr > 0) {
        oct = nbr % 8;
        nbr = nbr / 8;
    }
    my_put_nbr(oct);
    return nbr;
}

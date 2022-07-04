/*
** EPITECH PROJECT, 2021
** get nbr
** File description:
** get nbr
*/
#include "my.h"

int my_getnbr(char *str)
{
    int nbr = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr *10 + str[i] - 48;
        i++;
    }
    return nbr;
}

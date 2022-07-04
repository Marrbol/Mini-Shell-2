/*
** EPITECH PROJECT, 2021
** my.binaire
** File description:
** from dec to binaire
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int dec_to_binaire(int nbr)
{
    int tmpres = 0;
    int bin = 0;
    char *res = malloc(sizeof(char) * 10000000000);
    int i = 0;

    while (nbr > 0) {
        tmpres = nbr / 2;
        bin = nbr % 2;
        nbr = tmpres;
        res[i] = bin + '0';
        i++;
    }
    res = my_revstr(res);
    return my_getnbr(res);
}

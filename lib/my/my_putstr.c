/*
** EPITECH PROJECT, 2021
** put str
** File description:
** on va put un str
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const  *str)
{
    while (*str != '\0' ) {
        my_putchar(*str);
        str++;
    }
    return 0;
}

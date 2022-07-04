/*
** EPITECH PROJECT, 2021
** disp_stdarg
** File description:
** disp_stdarg
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        modulo = (nb % 10);
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(modulo + '0');
    } else {
        my_putchar(nb + '0');
    }
    return 0;
}

/*
** EPITECH PROJECT, 2025
** my_put_float
** File description:
** my_put_float
*/

#include "../../../include/biglib.h"

int my_floatlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        nb = -nb;
        len++;
    }
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}

int get_rounded(int nb)
{
    if ((nb % 10) > 5)
        nb += 10 - (nb % 10);
    return nb / 10;
}

void my_put_float(double nb, int decimal_precision)
{
    int entier = (int) nb;
    int decimal;
    int size = 1 + my_floatlen(entier) + decimal_precision;
    int base_1 = 1;

    for (int i = 1; i < decimal_precision + 2; i++){
        base_1 *= 10;
    }
    decimal = get_rounded((int) ((nb - entier) * base_1));
    my_put_number(entier);
    my_putchar('.');
    my_put_number(decimal);
}

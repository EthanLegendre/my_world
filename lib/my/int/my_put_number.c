/*
** EPITECH PROJECT, 2025
** my_put_number
** File description:
** my_put_number
*/

#include "../../../include/biglib.h"

void my_put_number(int nb)
{
    if (nb == -2147483648) {
        my_put_str("-2147483648");
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_put_number(nb / 10);
    my_putchar(nb % 10 + '0');
}

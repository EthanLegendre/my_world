/*
** EPITECH PROJECT, 2025
** my_put_long
** File description:
** my_put_long
*/

#include "../../../include/biglib.h"

void my_put_long(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_put_long(nb / 10);
    my_putchar(nb % 10 + '0');
}

/*
** EPITECH PROJECT, 2025
** get_int_len
** File description:
** get_int_len
*/

#include "../../../include/biglib.h"

int get_int_len(int nb)
{
    int i = 0;

    while (nb / 10){
        i++;
        nb /= 10;
    }
    i++;
    return i;
}

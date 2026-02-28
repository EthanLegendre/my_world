/*
** EPITECH PROJECT, 2025
** convert_int_to_str
** File description:
** convert_int_to_str
*/

#include "../../../include/biglib.h"

int my_int_len(int nb)
{
    int i = 1;

    while (nb > 10){
        i++;
        nb /= 10;
    }
    return i;
}

char *convert_int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (my_int_len(nb) + 1));
    int len = my_int_len(nb);
    int i = len - 1;

    while (i >= 0){
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
        i--;
    }
    str[len] = '\0';
    return str;
}

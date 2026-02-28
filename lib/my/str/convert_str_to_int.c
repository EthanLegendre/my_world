/*
** EPITECH PROJECT, 2025
** convert_str_to_int
** File description:
** convert_str_to_int
*/

#include "../../../include/biglib.h"

int convert_str_to_int(char *str)
{
    int i = 0;
    int nbr = 0;
    int base = 1;

    while (str[i]){
        nbr = nbr * 10 + (str[i] - '0');
        base *= 10;
        i++;
    }
    return nbr;
}

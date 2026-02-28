/*
** EPITECH PROJECT, 2025
** my_str_low_case
** File description:
** my_str_low_case
*/

#include "../../../include/biglib.h"

char *my_str_low_case(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}

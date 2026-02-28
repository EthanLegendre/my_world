/*
** EPITECH PROJECT, 2025
** my_str_up_case
** File description:
** my_str_up_case
*/

#include "../../../include/biglib.h"

char *my_str_up_case(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}

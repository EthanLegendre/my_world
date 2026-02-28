/*
** EPITECH PROJECT, 2025
** my_str_len
** File description:
** my_str_len
*/

#include "../../../include/biglib.h"

int my_str_len(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** my_revstr
*/

#include "../../../include/biglib.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_str_len(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}

/*
** EPITECH PROJECT, 2025
** my_str_cat
** File description:
** my_str_cat
*/

#include "../../../include/biglib.h"

char *my_str_cat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return dest;
}

/*
** EPITECH PROJECT, 2025
** my_str_ncat
** File description:
** my_str_ncat
*/

#include "../../../include/biglib.h"

char *my_str_ncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < nb) {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return dest;
}

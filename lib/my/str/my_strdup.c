/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** my_strdup
*/

#include "../../../include/biglib.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *dest;

    while (src[i])
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j < i; j++)
        dest[j] = src[j];
    dest[i] = '\0';
    return dest;
}

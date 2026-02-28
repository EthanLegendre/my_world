/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** my_strcmp
*/

#include "../../../include/biglib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    char c1;
    char c2;

    while (s1[i] != '\0' && s2[i] != '\0') {
        c1 = s1[i];
        c2 = s2[i];
        if (c1 != c2)
            return c1 - c2;
        i++;
    }
    return s1[i] - s2[i];
}

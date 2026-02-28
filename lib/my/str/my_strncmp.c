/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** my_strncmp
*/

#include "../../../include/biglib.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    char c1;
    char c2;

    while (i < n) {
        c1 = s1[i];
        c2 = s2[i];
        if (c1 != c2)
            return c1 - c2;
        if (c1 == '\0' || c2 == '\0')
            return c1 - c2;
        i++;
    }
    return 0;
}

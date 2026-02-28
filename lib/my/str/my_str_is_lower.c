/*
** EPITECH PROJECT, 2025
** my_str_is_lower
** File description:
** my_str_is_lower
*/

#include "../../../include/biglib.h"

int my_str_is_lower(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;
        i++;
    }
    return 1;
}

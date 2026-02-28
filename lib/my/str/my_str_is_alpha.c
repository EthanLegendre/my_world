/*
** EPITECH PROJECT, 2025
** my_str_is_alpha
** File description:
** my_str_is_alpha
*/

#include "../../../include/biglib.h"

int my_str_is_alpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= 'A' && str[i] <= 'Z')))
            return 0;
        i++;
    }
    return 1;
}

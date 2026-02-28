/*
** EPITECH PROJECT, 2025
** my_char_is_alpha
** File description:
** my_char_is_alpha
*/

#include "../../../include/biglib.h"

int my_char_is_alpha(char c)
{
    if (!((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')))
        return 0;
    return 1;
}

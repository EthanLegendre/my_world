/*
** EPITECH PROJECT, 2025
** my_str_is_upper
** File description:
** my_str_is_upper
*/

#include "../../../include/biglib.h"

int my_str_is_upper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z'){
            return 0;
        }
        i++;
    }
    return 1;
}

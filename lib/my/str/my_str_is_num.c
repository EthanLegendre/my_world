/*
** EPITECH PROJECT, 2025
** my_str_is_num
** File description:
** my_str_is_num
*/

#include "../../../include/biglib.h"

int my_str_is_num(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9'){
            return 0;
        }
        i++;
    }
    return 1;
}

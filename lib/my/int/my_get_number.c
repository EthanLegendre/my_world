/*
** EPITECH PROJECT, 2025
** my_get_number
** File description:
** my_get_number
*/

#include "../../../include/biglib.h"

int my_get_number(char const *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) {
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

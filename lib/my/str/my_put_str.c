/*
** EPITECH PROJECT, 2025
** my_put_str
** File description:
** my_put_str
*/

#include "../../../include/biglib.h"

int my_put_str(char *str)
{
    int i = 0;

    while (str[i]){
        my_putchar(str[i]);
        i++;
    }
    return 1;
}

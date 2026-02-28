/*
** EPITECH PROJECT, 2025
** check_char_in_str
** File description:
** check_char_in_str
*/

#include "../../../include/biglib.h"


int check_char_in_str(char *str, char c)
{
    int i = 0;

    while (str[i]){
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

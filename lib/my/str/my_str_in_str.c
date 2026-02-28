/*
** EPITECH PROJECT, 2025
** my_str_in_str
** File description:
** my_str_in_str
*/
#include "../../../include/biglib.h"

char counting(char *str, char *to_find)
{
    int countstr = my_str_len(str);
    int countfind = my_str_len(to_find);
    int i;
    int k;
    int found;

    for (k = 0; k < countfind; k++) {
        if (str[i + k] != to_find[k]) {
            found = 0;
        }
    }
    return 0;
}

char *my_str_in_str(char *str, char *to_find)
{
    int countstr = my_str_len(str);
    int countfind = my_str_len(to_find);
    int i;
    int k;
    int found;

    if (countfind > countstr) {
        return 0;
    }
    for (i = 0; i < countstr - countfind; i++) {
        found = 1;
        counting(str, to_find);
    }
    if (found == 1) {
        return str;
    }
    return 0;
}

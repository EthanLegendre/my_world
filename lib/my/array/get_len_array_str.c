/*
** EPITECH PROJECT, 2025
** get_len_array_str
** File description:
** get_len_array_str
*/

#include "../../../include/biglib.h"

int get_len_tab_str(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}

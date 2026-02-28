/*
** EPITECH PROJECT, 2025
** get_len_array_int
** File description:
** get_len_array_int
*/

#include "../../../include/biglib.h"

int get_len_tab_int(int **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}

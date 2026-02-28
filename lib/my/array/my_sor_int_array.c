/*
** EPITECH PROJECT, 2025
** my_sort_int_arr
** File description:
** my_sort_int_array
*/

#include "../../../include/biglib.h"

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int tmp;

    while (i < size - 1) {
        if (tab[i] > tab[i + 1]) {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        } else
            i++;
    }
}

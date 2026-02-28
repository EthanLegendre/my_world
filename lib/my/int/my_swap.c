/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** my_swap
*/

#include "../../../include/biglib.h"

void my_swap(int *a, int *b)
{
    int c;
    int d;

    c = *a;
    d = *b;
    *a = d;
    *b = c;
}

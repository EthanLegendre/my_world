/*
** EPITECH PROJECT, 2025
** mem_alloc_2d_array_int
** File description:
** mem_alloc_2d_array_int
*/

#include "../../../include/biglib.h"

int **mem_alloc_2d_array_int(int nbr_line, int nbr_column)
{
    int **array = malloc(sizeof(int *) * (nbr_line + 1));
    int i;

    for (i = 0; i < nbr_line; i++){
        array[i] = malloc(sizeof(int) * nbr_column);
    }
    array[nbr_line] = NULL;
    return array;
}

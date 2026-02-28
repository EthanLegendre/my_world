/*
** EPITECH PROJECT, 2025
** mem_alloc_2d_array_str
** File description:
** mem_alloc_2d_array_str
*/

#include "../../../include/biglib.h"

char **mem_alloc_2d_array_str(int nbr_line, int nbr_column)
{
    char **array = malloc(sizeof(char *) * (nbr_line + 1));
    int i;

    for (i = 0; i < nbr_line; i++){
        array[i] = malloc(sizeof(char) * (nbr_column + 1));
    }
    array[nbr_line] = NULL;
    return array;
}

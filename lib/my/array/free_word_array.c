/*
** EPITECH PROJECT, 2026
** free_word_array
** File description:
** free_word_array
*/

#include "../../../include/biglib.h"

void free_word_array(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

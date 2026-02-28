/*
** EPITECH PROJECT, 2026
** create_map
** File description:
** create_map
*/

#include "../../../include/my_world.h"

static sfVector2f **mem_alloc_2d_array_sfVector(int nbr_line, int nbr_column)
{
    sfVector2f **array = malloc(sizeof(sfVector2f *) * nbr_line);

    if (!array)
        return NULL;
    for (int i = 0; i < nbr_line; i++)
            array[i] =  malloc(sizeof(sfVector2f) * nbr_column);
    for (int i = 0; i < nbr_line; i++) {
        if (!array[i]) {
            for (int k = 0; k < i; k++)
                free(array[k]);
            free(array);
            return NULL;
        }
    }
    return array;
}

sfVector2f **create_2d_map_empty(int map_3d[MAP_Y][MAP_X], camera_t *camera)
{
    sfVector2f **map_2d = mem_alloc_2d_array_sfVector(MAP_Y, MAP_X);

    return map_2d;
}

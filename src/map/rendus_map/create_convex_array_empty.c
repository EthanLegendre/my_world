/*
** EPITECH PROJECT, 2026
** create_convex_array_empty.c
** File description:
** create_convex_array_empty.c
*/

#include "../../../include/my_world.h"

sfConvexShape ***mem_alloc_2d_array_sfconvex(int nbr_line, int nbr_column)
{
    sfConvexShape ***array = malloc(sizeof(*array) * nbr_line);

    if (!array)
        return NULL;
    for (int i = 0; i < nbr_line; i++) {
        array[i] = malloc(sizeof(**array) * nbr_column);
        for (int j = 0; j < nbr_column; j++)
            array[i][j] = NULL;
    }
    return array;
}

sfConvexShape ***create_convex_array_empty(void)
{
    sfConvexShape ***tab = mem_alloc_2d_array_sfconvex(MAP_Y, MAP_X);

    if (!tab)
        return NULL;
    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            tab[i][j] = sfConvexShape_create();
            sfConvexShape_setPointCount(tab[i][j], 4);
            sfConvexShape_setOutlineColor(tab[i][j], sfBlack);
            sfConvexShape_setOutlineThickness(tab[i][j], 0.4);
        }
    }
    return tab;
}

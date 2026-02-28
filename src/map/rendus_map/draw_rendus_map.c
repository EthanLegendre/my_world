/*
** EPITECH PROJECT, 2026
** draw_rendus_map
** File description:
** draw_rendus_map
*/

#include "../../../include/my_world.h"

static void draw_convex(sfRenderWindow *window, int i, sfConvexShape ***tab)
{
    for (int j = 0; j < MAP_X - 1; j++) {
        if (tab[i][j])
            sfRenderWindow_drawConvexShape(window, tab[i][j], NULL);
    }
}

int draw_rendus_map(sfRenderWindow *window, sfVector2f **map_2d, int map_3d[MAP_Y][MAP_X], sfConvexShape ***convex_tab)
{
    for (int i = 0; i < MAP_Y; i++)
        draw_convex(window, i, convex_tab);
    return 0;
}
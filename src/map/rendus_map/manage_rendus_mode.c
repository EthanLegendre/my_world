/*
** EPITECH PROJECT, 2026
** manage_rendus_mode
** File description:
** manage_rendus_mode
*/

#include "../../../include/my_world.h"

void manage_rendus_mode(sfConvexShape ***convex_tab1, sfConvexShape ***convex_tab2, int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d, camera_t *camera)
{
    fit_convex_by_map(convex_tab1, map_2d, map_3d, camera);
}

/*
** EPITECH PROJECT, 2026
** manage_rendus_mode
** File description:
** manage_rendus_mode
*/

#include "../../../include/my_world.h"

void manage_rendus_mode(sfConvexShape ***convex_tab1,
    int map_3d[MAP_Y][MAP_X], camera_t *camera, game_info_t *game_info)
{
    fit_convex_by_map(convex_tab1, map_3d, camera, game_info);
}

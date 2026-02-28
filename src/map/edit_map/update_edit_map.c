/*
** EPITECH PROJECT, 2026
** manage_edit_map
** File description:
** manage_edit_map
*/

#include "../../../include/my_world.h"

void update_iso_point(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d, camera_t *camera)
{
    for (int i = 0; i < MAP_Y; i++){
        for (int j = 0; j < MAP_X; j++)
            map_2d[i][j] = project_iso_point(SPACE * j, SPACE * i, map_3d[i][j], camera);
    }
}

void update_edit_map(int map_3d[MAP_Y][MAP_X], sfVector2i mouse_pos, camera_t *camera)
{
    sfVector2f current_point;

    for (int i = 0; i< MAP_Y; i++){
        for (int j = 0; j < MAP_X; j++){
            current_point = project_iso_point(SPACE * j, SPACE * i, map_3d[i][j], camera);
            change_z_by_select_point(map_3d, mouse_pos, i, j, current_point);
        }
    }
}
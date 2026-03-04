/*
** EPITECH PROJECT, 2026
** update_2d_map
** File description:
** update_2d_map
*/

#include "../../../include/my_world.h"

void manage_edit_mode(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d,
    camera_t *camera, game_info_t *game_info)
{
    manage_camera_pos(camera);
    update_iso_point(map_3d, map_2d, camera);
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        update_edit_map(map_3d, game_info, camera);
    }
}

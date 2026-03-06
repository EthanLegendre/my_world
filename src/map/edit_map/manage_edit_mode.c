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
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        game_info->weight += 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        game_info->weight -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        game_info->up = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        game_info->up = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        update_edit_map(map_3d, game_info, camera);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR))
        fill_map_with_perlin(map_3d, game_info->base_seed);
}

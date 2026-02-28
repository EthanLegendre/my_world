/*
** EPITECH PROJECT, 2026
** init_texture
** File description:
** init_texture
*/

#include "my_world.h"

void init_texture(game_info_t *game_info)
{
    if (!game_info)
        return;
    if (!game_info->water_texture)
        game_info->water_texture = NULL;
    if (!game_info->snow_texture)
        game_info->snow_texture = NULL;
    if (!game_info->herbe_texture)
        game_info->herbe_texture = NULL;
    if (!game_info->sand_texture)
        game_info->sand_texture = NULL;
}

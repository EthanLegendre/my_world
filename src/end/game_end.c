/*
** EPITECH PROJECT, 2025
** game_end
** File description:
** game_end
*/

#include "my_world.h"

void game_end(my_world_t *world_data)
{
    if (!world_data)
        return;
    if (world_data->menu)
        csfml_menu_destroy(world_data->menu);
    if (world_data->font_menu)
        sfFont_destroy(world_data->font_menu);
    if (world_data->ctx)
        csfml_context_close(world_data->ctx);
    free(world_data);
}

/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** loop key events
*/

#include "../loop_internal.h"

void loop_on_key_pressed(sfKeyCode key, void *user_data)
{
    world_runtime_t *runtime = user_data;
    game_info_t *game_info = NULL;

    if (!runtime || !runtime->init || !runtime->init->window)
        return;
    game_info = runtime->game_info;
    if (key == sfKeyV) {
        game_info->edit_mode = !game_info->edit_mode;
        if (game_info->edit_mode)
            update_iso_point(runtime->map_3d, runtime->map_2d,
                runtime->camera);
        else
            runtime->rendus_dirty = 1;
    }
    if (key == sfKeyEscape)
        sfRenderWindow_close(runtime->init->window);
}

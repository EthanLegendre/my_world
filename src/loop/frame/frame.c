/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** loop frame update
*/

#include "../loop_internal.h"

void loop_on_frame(csfml_context_t *ctx, float dt, void *user_data)
{
    world_runtime_t *runtime = user_data;

    (void)ctx;
    (void)dt;
    runtime->game_info->mouse_pos =
        sfMouse_getPositionRenderWindow(runtime->init->window);
    if (!runtime)
        return;
    if (runtime->game_info->edit_mode) {
        manage_edit_mode(runtime->map_3d, runtime->map_2d, runtime->camera,
            runtime->game_info);
        return;
    }
    if (!runtime->rendus_dirty)
        return;
    manage_rendus_mode(runtime->rendus_map, runtime->map_3d,
        runtime->camera, runtime->game_info);
    runtime->rendus_dirty = 0;
}

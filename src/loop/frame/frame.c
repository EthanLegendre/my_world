/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** loop frame update
*/

#include "../loop_internal.h"

static void call_rendus_mode(world_runtime_t *runtime)
{
    manage_rendus_mode(runtime->rendus_map, runtime->map_3d,
        runtime->camera, runtime->game_info);
    runtime->rendus_dirty = 0;
}

static int check_edit_mode(world_runtime_t *runtime)
{
    if (runtime->game_info->edit_mode) {
        manage_edit_mode(runtime->map_3d, runtime->map_2d, runtime->camera,
            runtime->game_info);
        return 0;
    }
    return 1;
}

void loop_on_frame(__attribute__((unused)) csfml_context_t *ctx,
    __attribute__((unused)) float dt, void *user_data)
{
    world_runtime_t *runtime = user_data;

    runtime->game_info->mouse_pos =
        sfMouse_getPositionRenderWindow(runtime->init->ctx->window);
    if (!runtime)
        return;
    if (runtime->init && runtime->init->map_seed_dirty) {
        if (fill_map_with_perlin(runtime->map_3d,
                runtime->init->map_seed) == 0) {
            update_iso_point(runtime->map_3d, runtime->map_2d, runtime->camera);
            runtime->rendus_dirty = 1;
        }
        runtime->init->map_seed_dirty = 0;
    }
    if (!check_edit_mode(runtime))
        return;
    if (!runtime->rendus_dirty)
        return;
    call_rendus_mode(runtime);
}

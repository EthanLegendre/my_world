/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** loop draw pass
*/

#include "../loop_internal.h"

void loop_on_draw(csfml_context_t *ctx, void *user_data)
{
    world_runtime_t *runtime = user_data;

    if (!runtime || !ctx || !ctx->window)
        return;
    if (runtime->game_info->edit_mode) {
        draw_edit_map(ctx->window, runtime->map_2d, runtime->map_3d);
    } else {
        draw_rendus_map(ctx->window, runtime->rendus_map);
    }
    if (runtime->init && runtime->init->menu)
        csfml_menu_draw(ctx->window, runtime->init->menu, NULL);
}

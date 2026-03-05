/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** loop key events
*/

#include <stdio.h>

#include "../loop_internal.h"

static
void loop_menu_mouse_move(int x, int y, void *user_data)
{
    world_runtime_t *runtime = user_data;
    sfEvent event;

    if (!runtime || !runtime->init || !runtime->init->menu ||
        !runtime->init->ctx || !runtime->init->ctx->window)
        return;
    if (!csfml_menu_is_open(runtime->init->menu))
        return;
    event.type = sfEvtMouseMoved;
    event.mouseMove.x = x;
    event.mouseMove.y = y;
    csfml_menu_handle_event(runtime->init->menu,
        runtime->init->ctx->window, &event);
}

static
void loop_menu_mouse_click(int x, int y, int button, void *user_data)
{
    world_runtime_t *runtime = user_data;
    sfEvent event;

    if (!runtime || !runtime->init || !runtime->init->menu ||
        !runtime->init->ctx || !runtime->init->ctx->window)
        return;
    if (!csfml_menu_is_open(runtime->init->menu))
        return;
    event.type = sfEvtMouseButtonPressed;
    event.mouseButton.button = button;
    event.mouseButton.x = x;
    event.mouseButton.y = y;
    csfml_menu_handle_event(runtime->init->menu,
        runtime->init->ctx->window, &event);
}

void loop_register_input_callbacks(world_runtime_t *runtime)
{
    if (!runtime || !runtime->init || !runtime->init->ctx)
        return;
    csfml_context_set_key_press_cb(runtime->init->ctx, loop_on_key_pressed);
    csfml_context_set_mouse_move_cb(runtime->init->ctx, loop_menu_mouse_move);
    csfml_context_set_mouse_click_cb(runtime->init->ctx, loop_menu_mouse_click);
}

void loop_on_key_pressed(sfKeyCode key, void *user_data)
{
    world_runtime_t *runtime = user_data;
    game_info_t *game_info = NULL;

    if (!runtime || !runtime->init || !runtime->init->ctx->window)
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
    if (key == sfKeyEscape) {
        csfml_menu_set_active_page(runtime->init->menu,
            runtime->init->pause_page_id);
        csfml_menu_open(runtime->init->menu);
    }
}

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** dispatch.c
*/

#include "init_project_private.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>


static
void csfml_dispatch_handle_mouse_click(csfml_context_t *ctx,
    const sfEvent *event)
{
    sfVector2i pixel;
    sfVector2f world;

    if (!ctx->on_mouse_click)
        return;
    pixel.x = event->mouseButton.x;
    pixel.y = event->mouseButton.y;
    world = sfRenderWindow_mapPixelToCoords(ctx->window, pixel, NULL);
    ctx->on_mouse_click((int)world.x, (int)world.y,
        event->mouseButton.button, ctx->user_data);
}

static
void csfml_dispatch_handle_mouse_move(csfml_context_t *ctx,
    const sfEvent *event)
{
    sfVector2i p = {event->mouseMove.x, event->mouseMove.y};
    sfVector2f w;

    if (!ctx->on_mouse_move)
        return;
    w = sfRenderWindow_mapPixelToCoords(ctx->window, p, NULL);
    ctx->on_mouse_move((int)w.x, (int)w.y, ctx->user_data);
}

static void csfml_dispatch_handle_key(csfml_context_t *ctx,
    const sfEvent *event)
{
    if (!ctx->on_key_press)
        return;
    ctx->on_key_press(event->key.code, ctx->user_data);
}

void csfml_dispatch_event(csfml_context_t *ctx, const sfEvent *event)
{
    if (!ctx || !ctx->window || !event)
        return;
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(ctx->window);
        return;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        csfml_dispatch_handle_mouse_click(ctx, event);
        return;
    }
    if (event->type == sfEvtMouseMoved) {
        csfml_dispatch_handle_mouse_move(ctx, event);
        return;
    }
    if (event->type == sfEvtKeyPressed) {
        csfml_dispatch_handle_key(ctx, event);
        return;
    }
}

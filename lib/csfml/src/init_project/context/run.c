/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** context run / loop
*/

#include "../../../includes/init_project.h"
#include "../../../includes/init_project_private.h"
#include "color.h"
#include <SFML/Window.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

int csfml_context_run(csfml_context_t *ctx,
    csfml_frame_cb_t frame_cb, csfml_draw_cb_t draw_cb,
    void *user_data)
{
    if (!ctx || !ctx->window)
        return -1;
    ctx->user_data = user_data;
    if (!ctx->clock)
        ctx->clock = sfClock_create();
    ctx->frame_accum = 0.0f;
    return csfml_context_loop(ctx, frame_cb, draw_cb);
}

int csfml_context_loop(csfml_context_t *ctx,
    csfml_frame_cb_t frame_cb, csfml_draw_cb_t draw_cb)
{
    sfEvent event;
    const float frame_time = 1.0f / 60.0f;

    while (sfRenderWindow_isOpen(ctx->window)) {
        while (sfRenderWindow_pollEvent(ctx->window, &event))
            csfml_dispatch_event(ctx, &event);
        if (!sfRenderWindow_isOpen(ctx->window))
            break;
        if (ctx->clock) {
            csfml_process_frame_accum(ctx, frame_cb, frame_time);
        }
        if (draw_cb) {
            sfRenderWindow_clear(ctx->window, BLACK);
            draw_cb(ctx, ctx->user_data);
            sfRenderWindow_display(ctx->window);
        } else {
            sfRenderWindow_display(ctx->window);
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** context event polling
*/

#include "init_project.h"
#include "init_project_private.h"
#include <SFML/Window.h>

int csfml_context_poll_events(csfml_context_t *ctx)
{
    sfEvent event;
    const float frame_time = 1.0f / 60.0f;

    if (!ctx || !ctx->window)
        return 0;
    while (sfRenderWindow_pollEvent(ctx->window, &event)) {
        csfml_dispatch_event(ctx, &event);
        if (!sfRenderWindow_isOpen(ctx->window))
            return 0;
    }
    if (ctx->on_frame && ctx->clock) {
        csfml_process_frame_accum(ctx, ctx->on_frame, frame_time);
    } else if (ctx->clock) {
        sfClock_restart(ctx->clock);
    }
    return sfRenderWindow_isOpen(ctx->window) ? 1 : 0;
}

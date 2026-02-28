/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** context frame accumulator
*/

#include "init_project.h"
#include <SFML/System/Clock.h>

void csfml_process_frame_accum(csfml_context_t *ctx,
    csfml_frame_cb_t frame_cb, float frame_time)
{
    sfTime elapsed = sfClock_restart(ctx->clock);
    const float dt = (float)elapsed.microseconds / 1000000.0f;

    ctx->frame_accum += dt;
    while (frame_cb && ctx->frame_accum >= frame_time) {
        frame_cb(ctx, frame_time, ctx->user_data);
        ctx->frame_accum -= frame_time;
    }
}

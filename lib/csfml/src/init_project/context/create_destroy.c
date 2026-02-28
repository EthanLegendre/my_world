/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** context create / destroy
*/

#include "init_project.h"
#include "init_project_private.h"
#include "sound.h"
#include "textures_simple.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>


static
int csfml_init_context_fields(csfml_context_t *ctx,
    unsigned int framerate_limit)
{
    if (!ctx)
        return -1;
    ctx->framerate_limit = framerate_limit;
    if (framerate_limit > 0 && ctx->window) {
        sfRenderWindow_setFramerateLimit(ctx->window, framerate_limit);
    }
    ctx->on_mouse_click = NULL;
    ctx->on_mouse_move = NULL;
    ctx->on_key_press = NULL;
    ctx->on_frame = NULL;
    ctx->frame_accum = 0.0f;
    ctx->user_data = NULL;
    ctx->textures_head = NULL;
    ctx->sounds_head = NULL;
    ctx->background_sprite = NULL;
    return 0;
}

csfml_context_t *csfml_context_create(const char *title, unsigned int width,
    unsigned int height, unsigned int framerate_limit)
{
    csfml_context_t *ctx = NULL;

    if (!title || width == 0 || height == 0)
        return NULL;
    ctx = malloc(sizeof(*ctx));
    if (!ctx)
        return NULL;
    if (csfml_setup_window_and_clock(ctx, title, width, height) != 0) {
        free(ctx);
        return NULL;
    }
    if (csfml_init_context_fields(ctx, framerate_limit) != 0) {
        csfml_context_destroy(ctx);
        return NULL;
    }
    return ctx;
}

void csfml_context_destroy(csfml_context_t *ctx)
{
    if (!ctx)
        return;
    if (ctx->background_sprite)
        sfSprite_destroy(ctx->background_sprite);
    if (ctx->clock)
        sfClock_destroy(ctx->clock);
    if (ctx->window)
        sfRenderWindow_destroy(ctx->window);
    free(ctx);
}

void csfml_cleanup_all(csfml_context_t *ctx)
{
    if (!ctx)
        return;
    csfml_tex_cleanup(ctx);
    csfml_sound_cleanup(ctx);
}

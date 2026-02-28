/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** setupp
*/

#include "init_project_private.h"
#include <SFML/Window.h>

int csfml_setup_window_and_clock(csfml_context_t *ctx,
    const char *title, unsigned int width, unsigned int height)
{
    sfVideoMode mode = {width, height, 32};

    ctx->window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    if (!ctx->window)
        return -1;
    ctx->clock = sfClock_create();
    if (!ctx->clock) {
        sfRenderWindow_destroy(ctx->window);
        ctx->window = NULL;
        return -1;
    }
    return 0;
}

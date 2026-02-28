/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** background helpers for csfml context
*/

#include "init_project.h"
#include "init_project_private.h"
#include "textures_simple.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static float background_compute_scale(sfRenderWindow *window,
    sfTexture *texture)
{
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2u texsz = sfTexture_getSize(texture);
    float sx;
    float sy;
    float scale;

    if (texsz.x == 0 || texsz.y == 0)
        return 1.0f;
    sx = (float)win.x / (float)texsz.x;
    sy = (float)win.y / (float)texsz.y;
    scale = (sx > sy) ? sx : sy;
    if (scale <= 0.0f)
        scale = 1.0f;
    return scale;
}

static void background_compute_pos(sfRenderWindow *window,
    sfTexture *texture, float scale, sfVector2f *pos_vec)
{
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2u texsz = sfTexture_getSize(texture);

    pos_vec->x = ((float)win.x - (float)texsz.x * scale) * 0.5f;
    pos_vec->y = ((float)win.y - (float)texsz.y * scale) * 0.5f;
}

static void background_configure_sprite(sfSprite *sprite,
    sfRenderWindow *window, sfTexture *texture)
{
    sfVector2f scale_vec;
    sfVector2f pos_vec;

    if (!sprite || !window || !texture)
        return;
    scale_vec.x = background_compute_scale(window, texture);
    scale_vec.y = scale_vec.x;
    background_compute_pos(window, texture, scale_vec.x, &pos_vec);
    sfSprite_setScale(sprite, scale_vec);
    sfSprite_setPosition(sprite, pos_vec);
}

int csfml_context_set_background_texture(csfml_context_t *ctx,
    sfTexture *texture)
{
    if (!ctx)
        return -1;
    if (ctx->background_sprite)
        sfSprite_destroy(ctx->background_sprite);
    if (!texture) {
        ctx->background_sprite = NULL;
        return 0;
    }
    ctx->background_sprite = sfSprite_create();
    if (!ctx->background_sprite)
        return -1;
    sfSprite_setTexture(ctx->background_sprite, texture, sfTrue);
    if (ctx->window)
        background_configure_sprite(ctx->background_sprite,
            ctx->window, texture);
    return 0;
}

int csfml_context_set_background_from_file(csfml_context_t *ctx,
    const char *key, const char *path)
{
    sfTexture *tex = NULL;

    if (!ctx || !key || !path)
        return -1;
    tex = csfml_tex_load(ctx, key, path);
    if (!tex)
        return -1;
    return csfml_context_set_background_texture(ctx, tex);
}

void csfml_context_clear_background(csfml_context_t *ctx)
{
    if (!ctx)
        return;
    if (ctx->background_sprite) {
        sfSprite_destroy(ctx->background_sprite);
        ctx->background_sprite = NULL;
    }
}

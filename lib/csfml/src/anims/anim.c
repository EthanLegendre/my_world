/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** animation helper implementation
*/

#include "anim.h"
#include "../../includes/anim.h"
#include "init_project.h"
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "../../includes/sprite.h"

csfml_anim_t *csfml_anim_create(sfTexture *tex, const sfIntRect *rect,
    float speed)
{
    csfml_anim_t *anim = NULL;
    sfVector2u ts;

    if (!tex || !rect)
        return NULL;
    anim = malloc(sizeof(*anim));
    if (!anim)
        return NULL;
    anim->sprite = csfml_sprite_create(tex, (sfIntRect *)rect);
    if (!anim->sprite) {
        free(anim);
        return NULL;
    }
    anim->rect = *rect;
    anim->frame_index = 0;
    ts = sfTexture_getSize(tex);
    anim->cols = (anim->rect.width > 0) ? (int)(ts.x / anim->rect.width) : 1;
    anim->anim_accum = 0.0f;
    anim->speed = speed;
    return anim;
}

void csfml_anim_destroy(csfml_anim_t *anim)
{
    if (!anim)
        return;
    if (anim->sprite)
        csfml_sprite_destroy(anim->sprite);
    free(anim);
}

void csfml_anim_frame(float dt, void *user_data)
{
    sfVector2f pos;
    csfml_anim_t *anim = NULL;

    anim = (csfml_anim_t *)user_data;
    if (!anim || !anim->sprite)
        return;
    pos = sfSprite_getPosition(anim->sprite);
    pos.x += anim->speed * dt;
    sfSprite_setPosition(anim->sprite, pos);
    anim->anim_accum += dt;
    if (anim->anim_accum >= 0.1f) {
        anim->anim_accum -= 0.1f;
        anim->frame_index = (anim->frame_index + 1) %
            (anim->cols > 0 ? anim->cols : 1);
        anim->rect.left = anim->frame_index * anim->rect.width;
        sfSprite_setTextureRect(anim->sprite, anim->rect);
    }
}

void csfml_anim_draw(csfml_context_t *cctx, void *user_data)
{
    csfml_anim_t *anim = (csfml_anim_t *)user_data;

    if (!anim || !anim->sprite)
        return;
    sfRenderWindow_drawSprite(cctx->window, anim->sprite, NULL);
}

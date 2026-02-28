/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu drawing and event dispatch
*/

#include "button.h"
#include "../../includes/button_utils.h"
#include <stdlib.h>

static
void csfml_button_init_bounds_from_texture(csfml_button_t *btn,
    sfTexture *texture)
{
    sfVector2u pos;

    if (!btn || !texture)
        return;
    pos = sfTexture_getSize(texture);
    btn->bounds.left = 0;
    btn->bounds.top = 0;
    btn->bounds.width = (int)pos.x;
    btn->bounds.height = (int)pos.y;
}

static void csfml_button_init_scales_and_defaults(csfml_button_t *btn)
{
    sfVector2f pos;
    sfVector2f orig;

    if (!btn || !btn->sprite)
        return;
    pos = sfSprite_getScale(btn->sprite);
    btn->normal_scale_x = pos.x;
    btn->normal_scale_y = pos.y;
    orig = sfSprite_getOrigin(btn->sprite);
    btn->normal_origin_x = orig.x;
    btn->normal_origin_y = orig.y;
    btn->hover_scale_x = pos.x * 1.03f;
    btn->hover_scale_y = pos.y * 1.03f;
    btn->hovered = 0;
    btn->hover_sound = NULL;
    btn->hover_enabled = 1;
    btn->hover_user_data = NULL;
    btn->click_sound = NULL;
}

static void csfml_button_setup_sprite_and_bounds(csfml_button_t *btn,
    sfTexture *texture, const sfIntRect *rect)
{
    if (!btn || !btn->sprite || !texture)
        return;
    sfSprite_setTexture(btn->sprite, texture, sfTrue);
    if (rect)
        btn->bounds = *rect;
    else
        csfml_button_init_bounds_from_texture(btn, texture);
    sfSprite_setTextureRect(btn->sprite, btn->bounds);
}

csfml_button_t *csfml_button_create(sfTexture *texture, const sfIntRect *rect,
    csfml_button_click_cb_t cb, void *user_data)
{
    csfml_button_t *btn = NULL;

    if (!texture) {
        return NULL;
    }
    btn = malloc(sizeof(*btn));
    if (!btn)
        return NULL;
    btn->sprite = sfSprite_create();
    btn->label = NULL;
    btn->font = NULL;
    if (!btn->sprite) {
        free(btn);
        return NULL;
    }
    csfml_button_setup_sprite_and_bounds(btn, texture, rect);
    btn->on_click = cb;
    btn->user_data = user_data;
    csfml_button_init_scales_and_defaults(btn);
    return btn;
}

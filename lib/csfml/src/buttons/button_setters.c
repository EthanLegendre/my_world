/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu drawing and event dispatch
*/

#include "button.h"
#include "../../includes/button_utils.h"
#include <SFML/Audio.h>

void csfml_button_set_hover_scale(csfml_button_t *btn, float sx, float sy)
{
    if (!btn)
        return;
    btn->hover_scale_x = sx;
    btn->hover_scale_y = sy;
}

void csfml_button_set_hover_sound(csfml_button_t *btn, sfSound *sound)
{
    if (!btn)
        return;
    btn->hover_sound = sound;
}

void csfml_button_set_hover_enabled(csfml_button_t *btn, int enabled)
{
    if (!btn)
        return;
    btn->hover_enabled = enabled ? 1 : 0;
    if (!btn->hover_enabled && btn->hovered) {
        btn->hovered = 0;
        csfml_set_sprite_scale_centered(btn->sprite,
            btn->normal_scale_x, btn->normal_scale_y);
    }
}

void csfml_button_set_position(csfml_button_t *btn, float x, float y)
{
    if (!btn)
        return;
    sfSprite_setPosition(btn->sprite, (sfVector2f){x, y});
}

void csfml_button_set_hover_user_data(csfml_button_t *btn, void *user_data)
{
    if (!btn)
        return;
    btn->hover_user_data = user_data;
}

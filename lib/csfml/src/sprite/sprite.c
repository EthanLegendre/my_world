/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** sprite helpers implementation
*/

#include "sprite.h"
#include <stdlib.h>

sfSprite *csfml_sprite_create(sfTexture *texture, const sfIntRect *area)
{
    sfSprite *s = NULL;

    if (!texture)
        return NULL;
    s = sfSprite_create();
    if (!s)
        return NULL;
    sfSprite_setTexture(s, texture, sfTrue);
    if (area)
        sfSprite_setTextureRect(s, *area);
    return s;
}

void csfml_sprite_destroy(sfSprite *sprite)
{
    if (!sprite)
        return;
    sfSprite_destroy(sprite);
}

void csfml_sprite_set_position(sfSprite *sprite, float x, float y)
{
    sfVector2f pos = { x, y };

    if (!sprite)
        return;
    sfSprite_setPosition(sprite, pos);
}

sfVector2f csfml_sprite_get_position(const sfSprite *sprite)
{
    if (!sprite)
        return (sfVector2f){0, 0};
    return sfSprite_getPosition((sfSprite *)sprite);
}

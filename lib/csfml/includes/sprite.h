/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** sprite helpers
*/

#ifndef CSFML_SPRITE_H
    #define CSFML_SPRITE_H

    #include <SFML/Graphics.h>

sfSprite *csfml_sprite_create(sfTexture *texture, const sfIntRect *area);
void csfml_sprite_destroy(sfSprite *sprite);
void csfml_sprite_set_position(sfSprite *sprite, float x, float y);
sfVector2f csfml_sprite_get_position(const sfSprite *sprite);

#endif

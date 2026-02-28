/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** spawn and frame callbacks
*/

#ifndef CSFML_BUTTON_UTILS_H
    #define CSFML_BUTTON_UTILS_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

int csfml_point_in_sprite(const sfSprite *s, int x, int y);
sfFloatRect csfml_expected_rect_from_sprite(const sfSprite *s);
void csfml_play_sound_with_user_volume(sfSound *sound, void *user_data);
void csfml_set_sprite_scale_safe(sfSprite *sprite, float sx, float sy);
void csfml_set_sprite_scale_centered(sfSprite *sprite, float sx, float sy);

#endif /* CSFML_BUTTON_UTILS_H */

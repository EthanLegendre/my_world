/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** spawn and frame callbacks
*/

#include "../../includes/button_utils.h"
#include "../../includes/sound.h"
#include <stdio.h>

int csfml_point_in_sprite(const sfSprite *sprite, int x, int y)
{
    sfFloatRect bounds;
    float fx = (float)x;
    float fy = (float)y;

    if (!sprite)
        return 0;
    bounds = sfSprite_getGlobalBounds((sfSprite *)sprite);
    if (fx >= bounds.left && fx <= bounds.left + bounds.width
        && fy >= bounds.top && fy <= bounds.top + bounds.height)
        return 1;
    return 0;
}

sfFloatRect csfml_expected_rect_from_sprite(const sfSprite *sprite)
{
    if (!sprite)
        return (sfFloatRect){0.0f, 0.0f, 0.0f, 0.0f};
    return sfSprite_getGlobalBounds((sfSprite *)sprite);
}

void csfml_play_sound_with_user_volume(sfSound *sound, void *user_data)
{
    int *volp = NULL;

    if (!sound)
        return;
    if (user_data) {
        volp = (int *)user_data;
        if (volp)
            sfSound_setVolume(sound, (float)(*volp));
    }
    csfml_sound_play(sound);
}

void csfml_set_sprite_scale_safe(sfSprite *sprite, float sx, float sy)
{
    if (!sprite)
        return;
    sfSprite_setScale(sprite, (sfVector2f){sx, sy});
}

void csfml_set_sprite_scale_centered(sfSprite *sprite, float sx, float sy)
{
    sfFloatRect old_bounds;
    sfVector2f old_center;
    sfFloatRect new_bounds;
    sfVector2f new_center;
    sfVector2f pos;

    if (!sprite)
        return;
    old_bounds = sfSprite_getGlobalBounds(sprite);
    old_center.x = old_bounds.left + old_bounds.width / 2.0f;
    old_center.y = old_bounds.top + old_bounds.height / 2.0f;
    sfSprite_setScale(sprite, (sfVector2f){sx, sy});
    new_bounds = sfSprite_getGlobalBounds(sprite);
    new_center.x = new_bounds.left + new_bounds.width / 2.0f;
    new_center.y = new_bounds.top + new_bounds.height / 2.0f;
    pos = sfSprite_getPosition(sprite);
    pos.x += (old_center.x - new_center.x);
    pos.y += (old_center.y - new_center.y);
    sfSprite_setPosition(sprite, pos);
}

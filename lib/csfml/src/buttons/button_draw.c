/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu drawing and event dispatch
*/

#include "button.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void csfml_button_destroy(csfml_button_t *btn)
{
    if (!btn)
        return;
    if (btn->sprite)
        sfSprite_destroy(btn->sprite);
    if (btn->label)
        sfText_destroy(btn->label);
    free(btn);
}

void csfml_button_draw(sfRenderWindow *win, csfml_button_t *btn,
    const sfRenderStates *states)
{
    sfFloatRect s_bounds;
    sfFloatRect t_bounds;

    if (!win || !btn)
        return;
    sfRenderWindow_drawSprite(win, btn->sprite, states);
    if (btn->label) {
        s_bounds = sfSprite_getGlobalBounds(btn->sprite);
        t_bounds = sfText_getLocalBounds(btn->label);
        sfText_setOrigin(btn->label,
            (sfVector2f){t_bounds.left + t_bounds.width / 2.0f,
                t_bounds.top + t_bounds.height / 2.0f});
        sfText_setPosition(btn->label,
            (sfVector2f){s_bounds.left + s_bounds.width / 2.0f,
                s_bounds.top + s_bounds.height / 2.0f});
        sfRenderWindow_drawText(win, btn->label, states);
    }
}

int csfml_button_set_label(csfml_button_t *btn,
    const csfml_button_label_info_t *info)
{
    if (!btn || !info || !info->text)
        return 0;
    if (!btn->label) {
        btn->label = sfText_create();
        if (!btn->label)
            return 0;
    }
    btn->font = info->font;
    if (info->font)
        sfText_setFont(btn->label, info->font);
    sfText_setString(btn->label, info->text);
    sfText_setCharacterSize(btn->label, info->char_size);
    if (info->color)
        sfText_setFillColor(btn->label, *info->color);
    else
        sfText_setFillColor(btn->label, (sfColor){255, 255, 255, 255});
    return 1;
}

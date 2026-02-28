/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector implementation
*/

#include "../../includes/selector.h"
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <stdio.h>

void sel_update_center_texture(csfml_selector_t *selector)
{
    sfIntRect r;
    sfTexture *t = NULL;

    if (!selector || !selector->center_btn)
        return;
    if (selector->shared_texture && selector->item_rects) {
        if (selector->item_count == 0)
            return;
        r = selector->item_rects[selector->current_index];
        sfSprite_setTexture(selector->center_btn->sprite,
            selector->shared_texture, sfTrue);
        sfSprite_setTextureRect(selector->center_btn->sprite, r);
        return;
    }
    if (selector->item_count == 0 || !selector->items)
        return;
    t = selector->items[selector->current_index];
    if (!t)
        return;
    sfSprite_setTexture(selector->center_btn->sprite, t, sfTrue);
}

void csfml_selector_destroy(csfml_selector_t *selector)
{
    if (!selector)
        return;
    if (selector->left_btn)
        csfml_button_destroy(selector->left_btn);
    if (selector->center_btn)
        csfml_button_destroy(selector->center_btn);
    if (selector->right_btn)
        csfml_button_destroy(selector->right_btn);
    if (selector->label)
        sfText_destroy(selector->label);
    if (selector->item_rects)
        free(selector->item_rects);
    free(selector);
}

void csfml_selector_draw(sfRenderWindow *win, csfml_selector_t *sel,
    const sfRenderStates *states)
{
    sfFloatRect cb;
    sfFloatRect lt;

    if (!sel)
        return;
    if (sel->left_btn)
        csfml_button_draw(win, sel->left_btn, states);
    if (sel->center_btn)
        csfml_button_draw(win, sel->center_btn, states);
    if (sel->right_btn)
        csfml_button_draw(win, sel->right_btn, states);
    if (sel->label && sel->center_btn) {
        cb = sfSprite_getGlobalBounds(sel->center_btn->sprite);
        lt = sfText_getLocalBounds(sel->label);
        sfText_setOrigin(sel->label, (sfVector2f){lt.left + lt.width / 2.0f,
                lt.top + lt.height / 2.0f});
        sfText_setPosition(sel->label, (sfVector2f){cb.left + cb.width / 2.0f,
                cb.top - lt.height / 2.0f + 5.0f});
        sfRenderWindow_drawText(win, sel->label, states);
    }
}

int csfml_selector_handle_event(csfml_selector_t *selector, const sfEvent *ev)
{
    if (!selector || !ev)
        return 0;
    if (selector->left_btn &&
        csfml_button_handle_event(selector->left_btn, ev)) {
        csfml_selector_left_button_cb(selector);
        return 1;
    }
    if (selector->right_btn &&
        csfml_button_handle_event(selector->right_btn, ev)) {
        csfml_selector_right_button_cb(selector);
        return 1;
    }
    if (selector->center_btn &&
        csfml_button_handle_event(selector->center_btn, ev))
        return 1;
    return 0;
}

void csfml_selector_set_position(csfml_selector_t *selector, float x, float y)
{
    float cx = x;
    sfFloatRect b;

    if (!selector)
        return;
    if (selector->left_btn) {
        csfml_button_set_position(selector->left_btn, cx, y);
        b = sfSprite_getGlobalBounds(selector->left_btn->sprite);
        cx += b.width + selector->padding;
    }
    if (selector->center_btn) {
        csfml_button_set_position(selector->center_btn, cx, y);
        b = sfSprite_getGlobalBounds(selector->center_btn->sprite);
        cx += b.width + selector->padding;
    }
    if (selector->right_btn) {
        csfml_button_set_position(selector->right_btn, cx, y);
    }
}

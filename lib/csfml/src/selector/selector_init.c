/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** selector_init file for my_hunter
*/

#include "../../includes/selector.h"
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>

static void selector_wire_buttons(csfml_selector_t *selector)
{
    if (selector->left_btn) {
        selector->left_btn->on_click = (csfml_button_click_cb_t)
            csfml_selector_left_button_cb;
        selector->left_btn->user_data = selector;
    }
    if (selector->right_btn) {
        selector->right_btn->on_click = (csfml_button_click_cb_t)
            csfml_selector_right_button_cb;
        selector->right_btn->user_data = selector;
    }
    if (selector->center_btn)
        selector->center_btn->user_data = selector;
}

static
void init_button(sfTexture *left_texture,
    sfTexture *right_texture, csfml_selector_t *selector)
{
    sfTexture *center_tex = NULL;

    if (selector->items && selector->item_count > 0)
        center_tex = selector->items[0];
    if (left_texture)
        selector->left_btn = csfml_button_create(left_texture,
            NULL, NULL, NULL);
    if (right_texture)
        selector->right_btn = csfml_button_create(right_texture,
            NULL, NULL, NULL);
    if (center_tex)
        selector->center_btn = csfml_button_create(center_tex,
            NULL, NULL, NULL);
    selector_wire_buttons(selector);
}

static void selector_init_fields(csfml_selector_t *selector,
    sfTexture **items, size_t item_count)
{
    selector->left_btn = NULL;
    selector->center_btn = NULL;
    selector->right_btn = NULL;
    selector->items = items;
    selector->item_count = item_count;
    selector->current_index = 0;
    selector->padding = 8.0f;
    selector->on_change = NULL;
    selector->on_change_user_data = NULL;
    selector->label = NULL;
    selector->label_font = NULL;
    selector->label_char_size = 0;
    selector->label_color = (sfColor){255, 255, 255, 255};
    selector->shared_texture = NULL;
    selector->item_rects = NULL;
}

csfml_selector_t *csfml_selector_create(sfTexture *left_texture,
    sfTexture *right_texture, sfTexture **items, size_t item_count)
{
    csfml_selector_t *selector = malloc(sizeof(csfml_selector_t));

    if (!selector)
        return NULL;
    selector_init_fields(selector, items, item_count);
    init_button(left_texture, right_texture, selector);
    return selector;
}

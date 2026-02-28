/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector wrapper/callback implementations
*/

#include "../../includes/selector.h"
#include <stdio.h>

void csfml_selector_left_button_cb(void *user_data)
{
    csfml_selector_t *selector = (csfml_selector_t *)user_data;

    if (!selector)
        return;
    if (selector->item_count == 0)
        return;
    if (selector->current_index == 0)
        selector->current_index = selector->item_count - 1;
    else
        selector->current_index--;
    sel_update_center_texture(selector);
    if (selector->on_change)
        selector->on_change(selector->current_index,
            selector->on_change_user_data);
}

void csfml_selector_right_button_cb(void *user_data)
{
    csfml_selector_t *selector = (csfml_selector_t *)user_data;

    if (!selector)
        return;
    if (selector->item_count == 0)
        return;
    selector->current_index = (selector->current_index + 1) %
        selector->item_count;
    sel_update_center_texture(selector);
    if (selector->on_change)
        selector->on_change(selector->current_index,
            selector->on_change_user_data);
}

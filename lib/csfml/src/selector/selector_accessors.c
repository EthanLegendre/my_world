/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector accessors
*/

#include "../../includes/selector.h"

size_t csfml_selector_get_index(const csfml_selector_t *selector)
{
    if (!selector)
        return 0;
    return selector->current_index;
}

void csfml_selector_set_index(csfml_selector_t *selector, size_t idx)
{
    if (!selector || selector->item_count == 0)
        return;
    selector->current_index = idx % selector->item_count;
    sel_update_center_texture(selector);
}

csfml_button_t *csfml_selector_get_left_button(csfml_selector_t *selector)
{
    if (!selector)
        return NULL;
    return selector->left_btn;
}

csfml_button_t *csfml_selector_get_center_button(csfml_selector_t *selector)
{
    if (!selector)
        return NULL;
    return selector->center_btn;
}

csfml_button_t *csfml_selector_get_right_button(csfml_selector_t *selector)
{
    if (!selector)
        return NULL;
    return selector->right_btn;
}

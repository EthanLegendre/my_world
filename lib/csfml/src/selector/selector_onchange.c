/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector onchange helpers
*/

#include "../../includes/selector.h"

void csfml_selector_set_on_change(csfml_selector_t *sel,
    void (*cb)(size_t idx, void *user_data), void *user_data)
{
    if (!sel)
        return;
    sel->on_change = cb;
    sel->on_change_user_data = user_data;
    if (sel->left_btn) {
        sel->left_btn->on_click = (csfml_button_click_cb_t)
            csfml_selector_left_button_cb;
        sel->left_btn->user_data = sel;
    }
    if (sel->right_btn) {
        sel->right_btn->on_click = (csfml_button_click_cb_t)
            csfml_selector_right_button_cb;
        sel->right_btn->user_data = sel;
    }
}

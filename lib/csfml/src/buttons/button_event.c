/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu drawing and event dispatch
*/

#include "button.h"
#include "../../includes/button_utils.h"
#include "../../includes/sound.h"
#include <stdio.h>

static
void csfml_button_enter_hover(csfml_button_t *btn)
{
    if (!btn)
        return;
    if (!btn->hovered) {
        btn->hovered = 1;
        if (btn->hover_enabled)
            csfml_set_sprite_scale_centered(btn->sprite,
                btn->hover_scale_x, btn->hover_scale_y);
        if (btn->hover_sound)
            csfml_play_sound_with_user_volume(btn->hover_sound,
                btn->hover_user_data);
    }
}

static
void csfml_button_leave_hover(csfml_button_t *btn)
{
    if (!btn)
        return;
    if (btn->hovered) {
        btn->hovered = 0;
        if (btn->hover_enabled)
            csfml_set_sprite_scale_centered(btn->sprite,
                btn->normal_scale_x, btn->normal_scale_y);
    }
}

static
int csfml_button_handle_click_event(csfml_button_t *btn,
    const sfEvent *event)
{
    int mx = event->mouseButton.x;
    int my = event->mouseButton.y;

    if (!csfml_point_in_sprite(btn->sprite, mx, my))
        return 0;
    if (btn->click_sound)
        csfml_play_sound_with_user_volume(btn->click_sound,
            btn->hover_user_data);
    if (btn->on_click)
        btn->on_click(btn->user_data);
    return 1;
}

int csfml_button_handle_event(csfml_button_t *btn, const sfEvent *event)
{
    int mx = 0;
    int my = 0;

    if (!btn || !event)
        return 0;
    if (event->type == sfEvtMouseButtonPressed) {
        return csfml_button_handle_click_event(btn, event);
    }
    if (event->type == sfEvtMouseMoved) {
        mx = event->mouseMove.x;
        my = event->mouseMove.y;
        if (csfml_point_in_sprite(btn->sprite, mx, my)) {
            csfml_button_enter_hover(btn);
            return 1;
        }
        csfml_button_leave_hover(btn);
        return 0;
    }
    return 0;
}

int csfml_button_handle_move(csfml_button_t *btn, int mx, int my)
{
    if (!btn)
        return 0;
    if (csfml_point_in_sprite(btn->sprite, mx, my)) {
        csfml_button_enter_hover(btn);
        return 1;
    }
    csfml_button_leave_hover(btn);
    return 0;
}

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** context setters
*/

#include "init_project.h"

void csfml_context_set_mouse_click_cb(csfml_context_t *ctx,
    csfml_mouse_click_cb_t cb)
{
    if (!ctx)
        return;
    ctx->on_mouse_click = cb;
}

void csfml_context_set_mouse_move_cb(csfml_context_t *ctx,
    csfml_mouse_move_cb_t cb)
{
    if (!ctx)
        return;
    ctx->on_mouse_move = cb;
}

void csfml_context_set_key_press_cb(csfml_context_t *ctx,
    csfml_key_press_cb_t cb)
{
    if (!ctx)
        return;
    ctx->on_key_press = cb;
}

void csfml_context_set_user_data(csfml_context_t *ctx, void *user_data)
{
    if (!ctx)
        return;
    ctx->user_data = user_data;
}

void csfml_context_set_frame_cb(csfml_context_t *ctx, csfml_frame_cb_t cb)
{
    if (!ctx)
        return;
    ctx->on_frame = cb;
}

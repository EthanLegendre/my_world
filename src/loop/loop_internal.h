/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** internal loop callbacks
*/

#ifndef LOOP_INTERNAL_H
    #define LOOP_INTERNAL_H

    #include "my_world.h"

void loop_on_key_pressed(sfKeyCode key, void *user_data);
void loop_on_frame(csfml_context_t *ctx, float dt, void *user_data);
void loop_on_draw(csfml_context_t *ctx, void *user_data);

#endif /* LOOP_INTERNAL_H */

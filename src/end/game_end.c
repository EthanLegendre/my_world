/*
** EPITECH PROJECT, 2025
** game_end
** File description:
** game_end
*/

#include "my_world.h"

void game_end(init_t *initialisation)
{
    if (!initialisation || !initialisation->ctx)
        return;
    csfml_context_close(initialisation->ctx);
    initialisation->ctx = NULL;
    initialisation->window = NULL;
}

/*
** EPITECH PROJECT, 2025
** game_end
** File description:
** game_end
*/

#include "../include/my_world.h"

void game_end(init_t *initialisation)
{
    sfRenderWindow_destroy(initialisation->window);
}

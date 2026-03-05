/*
** EPITECH PROJECT, 2025
** my_hunter_main
** File description:
** my_hunter_main
*/

#include "../include/my_world.h"
#include <unistd.h>
#include <stdio.h>

#include "menu/home.h"

int main(int argc, char **argv)
{
    my_world_t *initialisation = init();
    camera_t camera = {WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 4, 1, 45};
    game_info_t game_info = {0, 0, 0, 1};

    if (!initialisation->ctx || !initialisation->ctx->window)
        return 84;
    init_menu(initialisation);
    game_loop(initialisation, &camera, &game_info);
    game_end(initialisation);
    return 0;
}

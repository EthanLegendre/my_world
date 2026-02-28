/*
** EPITECH PROJECT, 2025
** init
** File description:
** inti
*/

#include "my_world.h"

init_t init(void)
{
    init_t init = {0};

    init.ctx = csfml_context_create("My world", WINDOW_SIZE_X,
        WINDOW_SIZE_Y, 60);
    if (!init.ctx)
        return init;
    init.window = init.ctx->window;
    sfRenderWindow_setKeyRepeatEnabled(init.window, sfFalse);
    return init;
}

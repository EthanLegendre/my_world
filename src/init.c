/*
** EPITECH PROJECT, 2025
** init
** File description:
** inti
*/

#include "../include/my_world.h"

init_t init(void)
{
    sfVideoMode video_mode = {WINDOW_SIZE_X, WINDOW_SIZE_Y, 32};
    sfRenderWindow *video_window = sfRenderWindow_create(video_mode,
        "My world", sfResize | sfClose, NULL);
    sfEvent video_event;
    init_t init;

    init.mode = video_mode;
    init.event = video_event;
    init.window = video_window;
    sfRenderWindow_setFramerateLimit(init.window, 60);
    return init;
}

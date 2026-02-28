/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** init_window file for my_hunter
*/

#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Window.h>
#include <stdbool.h>

static sfRenderWindow *
init_window(const sfVideoMode *mode,
    const char *title, const sfUint32 style,
    const sfContextSettings *settings)
{
    sfRenderWindow *window;

    if (!title || !mode)
        return NULL;
    window = sfRenderWindow_create(*mode, title, style, settings);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

sfRenderWindow *
create_window(const char *name, const sfUint32 style,
    const sfContextSettings *settings)
{
    const sfVideoMode mode = {1920, 1080, 32};

    return init_window(&mode, name, style, settings);
}

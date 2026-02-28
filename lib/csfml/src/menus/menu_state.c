/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu state helpers (open/close/debug)
*/

#include "../../includes/menu.h"

void csfml_menu_open(csfml_menu_t *menu)
{
    if (!menu)
        return;
    menu->open = 1;
}

void csfml_menu_close(csfml_menu_t *menu)
{
    if (!menu)
        return;
    menu->open = 0;
}

void csfml_menu_set_debug_hitboxes(csfml_menu_t *menu, int enabled)
{
    if (!menu)
        return;
    menu->debug_draw_hitboxes = enabled ? 1 : 0;
}

int csfml_menu_is_open(const csfml_menu_t *menu)
{
    if (!menu)
        return 0;
    return menu->open;
}

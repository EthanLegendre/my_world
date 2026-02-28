/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu page background helpers
*/

#include "../../includes/menu.h"
#include <stdlib.h>

int csfml_menu_set_page_background(csfml_menu_t *menu, int page_index,
    sfTexture *texture)
{
    menu_page_t *menu_page = NULL;

    if (!menu || !texture)
        return -1;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return -1;
    menu_page = &menu->pages[page_index];
    if (menu_page->background)
        sfSprite_destroy(menu_page->background);
    menu_page->background = sfSprite_create();
    if (!menu_page->background)
        return -1;
    sfSprite_setTexture(menu_page->background, texture, sfTrue);
    return 0;
}

int csfml_menu_set_page_background_rect(csfml_menu_t *menu, int page_index,
    sfTexture *texture, const sfIntRect *rect)
{
    menu_page_t *menu_page = NULL;

    if (!menu || !texture)
        return -1;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return -1;
    menu_page = &menu->pages[page_index];
    if (menu_page->background)
        sfSprite_destroy(menu_page->background);
    menu_page->background = sfSprite_create();
    if (!menu_page->background)
        return -1;
    sfSprite_setTexture(menu_page->background, texture, sfTrue);
    if (rect)
        sfSprite_setTextureRect(menu_page->background, *rect);
    return 0;
}

int csfml_menu_set_page_background_scale(csfml_menu_t *menu, int page_index,
    float scale_x, float scale_y)
{
    menu_page_t *menu_page = NULL;

    if (!menu)
        return -1;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return -1;
    menu_page = &menu->pages[page_index];
    if (!menu_page->background)
        return -1;
    sfSprite_setScale(menu_page->background, (sfVector2f){scale_x, scale_y});
    return 0;
}

void csfml_menu_clear_page_background(csfml_menu_t *menu, int page_index)
{
    menu_page_t *menu_page = NULL;

    if (!menu)
        return;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return;
    menu_page = &menu->pages[page_index];
    if (menu_page->background) {
        sfSprite_destroy(menu_page->background);
        menu_page->background = NULL;
    }
}

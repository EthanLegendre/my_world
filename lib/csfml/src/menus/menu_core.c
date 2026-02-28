/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu core: create/destroy/open/close
*/

#include "../../includes/menu.h"
#include <stdlib.h>

static void destroy_text(menu_page_t *menu_page)
{
    for (size_t i = 0; i < menu_page->text_count; ++i) {
        if (menu_page->texts[i])
            sfText_destroy(menu_page->texts[i]);
    }
}

static void csfml_menu_destroy_page(menu_page_t *menu_page)
{
    if (!menu_page)
        return;
    if (menu_page->buttons) {
        for (size_t i = 0; i < menu_page->count; ++i)
            csfml_button_destroy(menu_page->buttons[i]);
        free(menu_page->buttons);
    }
    if (menu_page->texts) {
        destroy_text(menu_page);
        free(menu_page->texts);
    }
    if (menu_page->background)
        sfSprite_destroy(menu_page->background);
    free(menu_page->title);
}

static void csfml_menu_init_pages(csfml_menu_t *menu)
{
    if (!menu || !menu->pages)
        return;
    for (size_t i = 0; i < menu->page_capacity; ++i) {
        menu->pages[i].title = NULL;
        menu->pages[i].buttons = NULL;
        menu->pages[i].count = 0;
        menu->pages[i].capacity = 0;
        menu->pages[i].background = NULL;
        menu->pages[i].texts = NULL;
        menu->pages[i].text_count = 0;
        menu->pages[i].text_capacity = 0;
    }
}

csfml_menu_t *csfml_menu_create(void)
{
    csfml_menu_t *menu = malloc(sizeof(*menu));

    if (!menu)
        return NULL;
    menu->pages = malloc(DEFAULT_CAP * sizeof(*menu->pages));
    if (!menu->pages) {
        free(menu);
        return NULL;
    }
    menu->page_capacity = DEFAULT_CAP;
    csfml_menu_init_pages(menu);
    menu->page_count = 0;
    menu->active_page = -1;
    menu->open = 0;
    menu->debug_draw_hitboxes = 0;
    return menu;
}

void csfml_menu_destroy(csfml_menu_t *menu)
{
    if (!menu)
        return;
    for (size_t p = 0; p < menu->page_count; ++p)
        csfml_menu_destroy_page(&menu->pages[p]);
    free(menu->pages);
    free(menu);
}

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu pages and buttons management
*/

#include "../../includes/menu.h"
#include <stdlib.h>
#include "my.h"

static void csfml_menu_init_page_entries(menu_page_t *pages,
    size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i) {
        pages[i].title = NULL;
        pages[i].buttons = NULL;
        pages[i].count = 0;
        pages[i].capacity = 0;
        pages[i].background = NULL;
        pages[i].texts = NULL;
        pages[i].text_count = 0;
        pages[i].text_capacity = 0;
    }
}

static void csfml_fill_button_ptrs_null(csfml_button_t **arr,
    size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
        arr[i] = NULL;
}

static
void csfml_menu_init_page(menu_page_t *menu_page, const char *title)
{
    if (!menu_page)
        return;
    menu_page->title = my_strdup(title ? title : "");
    menu_page->buttons = malloc(DEFAULT_CAP * sizeof(*menu_page->buttons));
    if (!menu_page->buttons) {
        free(menu_page->title);
        menu_page->title = NULL;
        return;
    }
    for (size_t i = 0; i < DEFAULT_CAP; ++i)
        menu_page->buttons[i] = NULL;
    menu_page->count = 0;
    menu_page->capacity = DEFAULT_CAP;
    menu_page->background = NULL;
    menu_page->texts = NULL;
    menu_page->text_count = 0;
    menu_page->text_capacity = 0;
}

static
int csfml_menu_ensure_page_capacity(csfml_menu_t *menu)
{
    size_t newcap = 0;
    menu_page_t *menu_page = NULL;

    if (menu->page_count >= menu->page_capacity) {
        newcap = menu->page_capacity * 2;
        menu_page = malloc(newcap * sizeof(*menu_page));
        if (!menu_page)
            return -1;
        for (size_t i = 0; i < menu->page_capacity; ++i)
            menu_page[i] = menu->pages[i];
        csfml_menu_init_page_entries(menu_page, menu->page_capacity, newcap);
        free(menu->pages);
        menu->pages = menu_page;
        menu->page_capacity = newcap;
    }
    return 0;
}

static
int csfml_menu_page_ensure_capacity(menu_page_t *menu_page)
{
    size_t newcap = 0;
    csfml_button_t **n = NULL;

    if (menu_page->count >= menu_page->capacity) {
        newcap = menu_page->capacity * 2;
        n = malloc(newcap * sizeof(*n));
        if (!n)
            return -1;
        for (size_t i = 0; i < menu_page->capacity; ++i)
            n[i] = menu_page->buttons[i];
        csfml_fill_button_ptrs_null(n, menu_page->capacity, newcap);
        free(menu_page->buttons);
        menu_page->buttons = n;
        menu_page->capacity = newcap;
    }
    return 0;
}

static
menu_page_t *csfml_menu_get_page_for_write(csfml_menu_t *menu,
    int page_index)
{
    if (!menu)
        return NULL;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return NULL;
    return &menu->pages[page_index];
}

int csfml_menu_add_page(csfml_menu_t *menu, const char *title)
{
    menu_page_t *menu_page = NULL;
    int idx = (int)menu->page_count;

    if (!menu)
        return -1;
    if (csfml_menu_ensure_page_capacity(menu) < 0)
        return -1;
    csfml_menu_init_page(&menu->pages[menu->page_count], title);
    menu_page = &menu->pages[menu->page_count];
    if (!menu_page->buttons)
        return -1;
    menu->page_count++;
    if (menu->active_page == -1)
        menu->active_page = idx;
    return idx;
}

int csfml_menu_set_active_page(csfml_menu_t *menu, int page_index)
{
    if (!menu)
        return -1;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return -1;
    menu->active_page = page_index;
    return 0;
}

int csfml_menu_find_page(const csfml_menu_t *menu, const char *title)
{
    if (!menu || !title)
        return -1;
    for (size_t i = 0; i < menu->page_count; ++i)
        if (menu->pages[i].title && my_strcmp(menu->pages[i].title, title) == 0)
            return (int)i;
    return -1;
}

int csfml_menu_add_button_to_page(csfml_menu_t *menu, int page_index,
    csfml_button_t *btn)
{
    menu_page_t *menu_page = NULL;
    size_t idx = 0;

    if (!btn)
        return -1;
    menu_page = csfml_menu_get_page_for_write(menu, page_index);
    if (!menu_page)
        return -1;
    if (!menu_page->buttons)
        return -1;
    if (csfml_menu_page_ensure_capacity(menu_page) < 0)
        return -1;
    idx = menu_page->count;
    menu_page->buttons[idx] = btn;
    menu_page->count++;
    return 0;
}

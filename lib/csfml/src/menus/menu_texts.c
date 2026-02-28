/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu page sfText helpers
*/

#include "../../includes/menu.h"
#include <stdlib.h>
#include <string.h>

static int init_text_array(menu_page_t *page)
{
    if (!page)
        return -1;
    page->text_capacity = DEFAULT_CAP;
    page->texts = malloc(page->text_capacity * sizeof(*page->texts));
    if (!page->texts)
        return -1;
    for (size_t i = 0; i < page->text_capacity; ++i)
        page->texts[i] = NULL;
    page->text_count = 0;
    return 0;
}

static int grow_text_array(menu_page_t *page)
{
    size_t nc = page->text_capacity * 2;
    sfText **n = malloc(nc * sizeof(*n));

    if (!n)
        return -1;
    for (size_t i = 0; i < page->text_capacity; ++i)
        n[i] = page->texts[i];
    for (size_t i = page->text_capacity; i < nc; ++i)
        n[i] = NULL;
    free(page->texts);
    page->texts = n;
    page->text_capacity = nc;
    return 0;
}

static int ensure_text_capacity(menu_page_t *page)
{
    if (!page)
        return -1;
    if (page->text_capacity == 0)
        return init_text_array(page);
    if (page->text_count >= page->text_capacity)
        return grow_text_array(page);
    return 0;
}

int csfml_menu_add_text_to_page(csfml_menu_t *menu, int page_index,
    sfText *text)
{
    menu_page_t *page = NULL;

    if (!menu || !text)
        return -1;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return -1;
    page = &menu->pages[page_index];
    if (ensure_text_capacity(page) < 0)
        return -1;
    page->texts[page->text_count] = text;
    page->text_count++;
    return 0;
}

void csfml_menu_clear_page_texts(csfml_menu_t *menu, int page_index)
{
    menu_page_t *page = NULL;

    if (!menu)
        return;
    if (page_index < 0 || (size_t)page_index >= menu->page_count)
        return;
    page = &menu->pages[page_index];
    if (!page->texts)
        return;
    for (size_t i = 0; i < page->text_count; ++i) {
        if (page->texts[i]) {
            sfText_destroy(page->texts[i]);
            page->texts[i] = NULL;
        }
    }
    free(page->texts);
    page->texts = NULL;
    page->text_capacity = 0;
    page->text_count = 0;
}

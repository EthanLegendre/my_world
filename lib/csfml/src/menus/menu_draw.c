/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** menu drawing and event dispatch
*/

#include "../../includes/menu.h"
#include <SFML/Graphics.h>
#include "../../includes/selector.h"

static
void draw_page_texts(sfRenderWindow *window, menu_page_t *menu_page,
    const sfRenderStates *states)
{
    if (!menu_page || !menu_page->texts)
        return;
    for (size_t i = 0; i < menu_page->text_count; ++i) {
        if (menu_page->texts[i])
            sfRenderWindow_drawText(window, menu_page->texts[i], states);
    }
}

static
void draw_button_hitbox(sfRenderWindow *window, const sfSprite *sprite,
    const sfRenderStates *states)
{
    sfFloatRect rect;
    sfRectangleShape *r = NULL;
    sfVector2f size;
    sfVector2f pos;

    if (!sprite || !window)
        return;
    rect = sfSprite_getGlobalBounds(sprite);
    r = sfRectangleShape_create();
    size.x = rect.width;
    size.y = rect.height;
    pos.x = rect.left;
    pos.y = rect.top;
    sfRectangleShape_setSize(r, size);
    sfRectangleShape_setPosition(r, pos);
    sfRectangleShape_setFillColor(r, (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOutlineColor(r, (sfColor){255, 0, 0, 200});
    sfRectangleShape_setOutlineThickness(r, 2.0f);
    sfRenderWindow_drawRectangleShape(window, r, states);
    sfRectangleShape_destroy(r);
}

static
void maybe_draw_selector_for_button(sfRenderWindow *window,
    csfml_button_t *btn, const sfRenderStates *states)
{
    csfml_selector_t *selector = NULL;

    if (!btn || !btn->user_data)
        return;
    selector = (csfml_selector_t *)btn->user_data;
    if (selector && selector->center_btn == btn)
        csfml_selector_draw(window, selector, states);
}

static
void draw_page_buttons(sfRenderWindow *window, menu_page_t *menu_page,
    const sfRenderStates *states, int debug_draw_hitboxes)
{
    csfml_button_t *btn = NULL;

    if (!menu_page)
        return;
    for (size_t i = 0; i < menu_page->count; ++i) {
        btn = menu_page->buttons[i];
        csfml_button_draw(window, btn, states);
        if (!btn)
            continue;
        if (debug_draw_hitboxes)
            draw_button_hitbox(window, btn->sprite, states);
        maybe_draw_selector_for_button(window, btn, states);
    }
}

static
int handle_buttons_move(menu_page_t *menu_page, int mx, int my)
{
    size_t idx = 0;
    int handled = 0;
    csfml_button_t *btn = NULL;

    if (!menu_page)
        return 0;
    for (size_t i = menu_page->count; i > 0; --i) {
        idx = i - 1;
        btn = menu_page->buttons[idx];
        if (!btn)
            continue;
        if (csfml_button_handle_move(btn, mx, my))
            handled = 1;
    }
    return handled;
}

static
int handle_page_mouse_move(menu_page_t *menu_page, sfRenderWindow *window)
{
    sfVector2i mpos;

    if (!menu_page || !window)
        return 0;
    mpos = sfMouse_getPositionRenderWindow(window);
    return handle_buttons_move(menu_page, mpos.x, mpos.y);
}

static
int handle_page_events(menu_page_t *menu_page, const sfEvent *event)
{
    size_t idx = 0;
    csfml_button_t *btn = NULL;

    if (!menu_page || !event)
        return 0;
    for (size_t i = menu_page->count; i > 0; --i) {
        idx = i - 1;
        btn = menu_page->buttons[idx];
        if (!btn)
            continue;
        if (csfml_button_handle_event(btn, event))
            return 1;
    }
    return 0;
}

void csfml_menu_draw(sfRenderWindow *window, csfml_menu_t *menu,
    const sfRenderStates *states)
{
    menu_page_t *menu_page = NULL;

    if (!menu || !window || !menu->open)
        return;
    if (menu->active_page < 0)
        return;
    menu_page = &menu->pages[menu->active_page];
    if (menu_page->background)
        sfRenderWindow_drawSprite(window, menu_page->background, states);
    draw_page_buttons(window, menu_page, states, menu->debug_draw_hitboxes);
    draw_page_texts(window, menu_page, states);
}

int csfml_menu_handle_event(csfml_menu_t *menu, sfRenderWindow *window,
    const sfEvent *event)
{
    menu_page_t *menu_page = NULL;

    if (!menu || !window || !event)
        return 0;
    if (!menu->open)
        return 0;
    if (menu->active_page < 0)
        return 0;
    menu_page = &menu->pages[menu->active_page];
    if (event->type == sfEvtMouseMoved)
        return handle_page_mouse_move(menu_page, window);
    return handle_page_events(menu_page, event);
}

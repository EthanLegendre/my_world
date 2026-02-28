/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** simple menu API built on buttons
*/

#ifndef CSFML_MENU_H
    #define CSFML_MENU_H


    #include <SFML/Graphics.h>
    #include "button.h"

    #define DEFAULT_CAP 8


typedef struct menu_page {
    char *title;
    struct csfml_button **buttons;
    size_t count;
    size_t capacity;
    sfSprite *background;
    sfText **texts;
    size_t text_count;
    size_t text_capacity;
} menu_page_t;

struct csfml_menu {
    menu_page_t *pages;
    size_t page_count;
    size_t page_capacity;
    int active_page;
    int open;
    int debug_draw_hitboxes;
} typedef csfml_menu_t;

csfml_menu_t *csfml_menu_create(void);
void csfml_menu_destroy(csfml_menu_t *menu);

/* management */
int csfml_menu_add_page(csfml_menu_t *menu, const char *title);
int csfml_menu_set_active_page(csfml_menu_t *menu, int page_index);
int csfml_menu_find_page(const csfml_menu_t *menu, const char *title);
int csfml_menu_add_button_to_page(csfml_menu_t *menu,
    int page_index, csfml_button_t *btn);
int csfml_menu_add_text_to_page(csfml_menu_t *menu, int page_index,
    sfText *text);
void csfml_menu_clear_page_texts(csfml_menu_t *menu, int page_index);

/* page background management */
int csfml_menu_set_page_background(csfml_menu_t *menu, int page_index,
    sfTexture *texture);
int csfml_menu_set_page_background_rect(csfml_menu_t *menu, int page_index,
    sfTexture *texture, const sfIntRect *rect);
int csfml_menu_set_page_background_scale(csfml_menu_t *menu, int page_index,
    float scale_x, float scale_y);
void csfml_menu_clear_page_background(csfml_menu_t *menu, int page_index);

/* Open/close */
void csfml_menu_open(csfml_menu_t *menu);
void csfml_menu_close(csfml_menu_t *menu);
int csfml_menu_is_open(const csfml_menu_t *menu);

/* Draw/handle (only open) */
void csfml_menu_draw(sfRenderWindow *win, csfml_menu_t *menu,
    const sfRenderStates *states);
int csfml_menu_handle_event(csfml_menu_t *menu, sfRenderWindow *win,
    const sfEvent *event);

/* Debug helpers */
void csfml_menu_set_debug_hitboxes(csfml_menu_t *menu, int enabled);

#endif

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector.h
*/

#ifndef CSFML_SELECTOR_H
    #define CSFML_SELECTOR_H

    #include <SFML/Graphics.h>
    #include "button.h"

typedef struct csfml_selector {
    csfml_button_t *left_btn;
    csfml_button_t *center_btn;
    csfml_button_t *right_btn;
    sfTexture **items;
    size_t item_count;
    size_t current_index;
    float padding;
    sfTexture *shared_texture;
    sfIntRect *item_rects;
    void (*on_change)(size_t idx, void *user_data);
    void *on_change_user_data;
    sfText *label;
    sfFont *label_font;
    unsigned int label_char_size;
    sfColor label_color;
} csfml_selector_t;


typedef struct csfml_selector_label_info {
    const char *text;
    sfFont *font;
    unsigned int char_size;
    sfColor *color;
} csfml_selector_label_info_t;


/* create/destroy */
csfml_selector_t *csfml_selector_create(sfTexture *left_texture,
    sfTexture *right_texture, sfTexture **items, size_t item_count);
void csfml_selector_destroy(csfml_selector_t *sel);

/* draw/handle */
void csfml_selector_draw(sfRenderWindow *win, csfml_selector_t *sel,
    const sfRenderStates *states);
int csfml_selector_handle_event(csfml_selector_t *sel, const sfEvent *ev);

/* helpers */
void csfml_selector_set_position(csfml_selector_t *sel, float x, float y);
void csfml_selector_set_padding(csfml_selector_t *sel, float pad);
size_t csfml_selector_get_index(const csfml_selector_t *sel);
void csfml_selector_set_index(csfml_selector_t *sel, size_t idx);
void sel_update_center_texture(csfml_selector_t *sel);

/* on-change callback */
void csfml_selector_set_on_change(csfml_selector_t *sel,
    void (*cb)(size_t idx, void *user_data), void *user_data);

/* button callbacks you can assign to selector buttons */
void csfml_selector_left_button_cb(void *user_data);
void csfml_selector_right_button_cb(void *user_data);

/* label helpers*/
int csfml_selector_set_label(csfml_selector_t *sel,
    const csfml_selector_label_info_t *info);
int csfml_selector_set_label_info(csfml_selector_t *sel,
    const csfml_selector_label_info_t *info);

csfml_button_t *csfml_selector_get_left_button(csfml_selector_t *sel);
csfml_button_t *csfml_selector_get_center_button(csfml_selector_t *sel);
csfml_button_t *csfml_selector_get_right_button(csfml_selector_t *sel);

#endif

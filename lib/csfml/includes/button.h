/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** button API with function-pointer callbacks
*/

#ifndef CSFML_BUTTON_H
    #define CSFML_BUTTON_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct csfml_button csfml_button_t;
typedef void (* csfml_button_click_cb_t)(void *user_data);
typedef struct csfml_button_label_info {
    const char *text;
    sfFont *font;
    unsigned int char_size;
    sfColor *color;
} csfml_button_label_info_t;
struct csfml_button {
    sfSprite *sprite;
    sfIntRect bounds;
    csfml_button_click_cb_t on_click;
    void *user_data;
    sfText *label;
    sfFont *font;
    float normal_scale_x;
    float normal_scale_y;
    float hover_scale_x;
    float hover_scale_y;
    float normal_origin_x;
    float normal_origin_y;
    int hovered;
    sfSound *hover_sound;
    int hover_enabled;
    void *hover_user_data;
    sfSound *click_sound;
};

int csfml_button_set_label(csfml_button_t *btn,
    const csfml_button_label_info_t *info);
csfml_button_t *csfml_button_create(sfTexture *texture, const sfIntRect *rect,
    csfml_button_click_cb_t cb, void *user_data);
void csfml_button_destroy(csfml_button_t *btn);
void csfml_button_draw(sfRenderWindow *win, csfml_button_t *btn,
    const sfRenderStates *states);
int csfml_button_handle_event(csfml_button_t *btn, const sfEvent *event);
int csfml_button_handle_move(csfml_button_t *btn, int mx, int my);
void csfml_button_set_position(csfml_button_t *btn, float x, float y);
void csfml_button_set_hover_scale(csfml_button_t *btn, float sx, float sy);
void csfml_button_set_hover_sound(csfml_button_t *btn, sfSound *sound);
void csfml_button_set_hover_enabled(csfml_button_t *btn, int enabled);
void csfml_button_set_hover_user_data(csfml_button_t *btn, void *user_data);
void csfml_button_set_click_sound(csfml_button_t *btn, sfSound *sound);

#endif

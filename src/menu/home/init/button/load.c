/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** load file for my_world
*/

#include <stdio.h>

#include "menu/home.h"

static
void load_btn_cb(void *user_data)
{
    my_world_t *world_data = user_data;
    int load_page_id = 0;

    if (!world_data || !world_data->menu)
        return;
    load_page_id = world_data->load_page_id;
    printf("load_page_id %d\n", load_page_id);
    if (load_page_id >= 0)
        csfml_menu_set_active_page(world_data->menu, load_page_id);
    csfml_menu_open(world_data->menu);
}

static void load_btn_center(csfml_button_t *btn,
    const sfRenderWindow *window, float y)
{
    sfFloatRect float_rect = {0};
    sfVector2u vector2_u = {0};
    float x_position = 0.0f;

    if (!btn || !window)
        return;
    sfSprite_setScale(btn->sprite, (sfVector2f){1.0f, 1.0f});
    float_rect = sfSprite_getGlobalBounds(btn->sprite);
    vector2_u = sfRenderWindow_getSize((sfRenderWindow *)window);
    x_position = ((float)vector2_u.x - float_rect.width) / 2.0f;
    sfSprite_setPosition(btn->sprite, (sfVector2f){x_position, y});
}

static void load_btn_add_to_menu(my_world_t *world_data,
    csfml_button_t *btn)
{
    if (!world_data || !world_data->menu)
        return;
    csfml_menu_add_button_to_page(world_data->menu,
        world_data->main_page_id,
        btn);
}

csfml_button_t *init_button_load(
    my_world_t *world_data,
    sfTexture *menu_tex,
    sfFont *font,
    const sfRenderWindow *window)
{
    sfIntRect btn_rect = {50, 455, 308, 95};
    csfml_button_t *b_load;
    csfml_button_label_info_t info;

    b_load = csfml_button_create(menu_tex, &btn_rect,
        load_btn_cb, world_data);
    if (b_load) {
        info.text = "Load";
        info.font = font;
        info.char_size = 45;
        info.color = &sfWhite;
        csfml_button_set_label(b_load, &info);
        apply_menu_button_sounds(world_data, b_load);
        load_btn_center(b_load, window, 480.0f);
        load_btn_add_to_menu(world_data, b_load);
    }
    return b_load;
}

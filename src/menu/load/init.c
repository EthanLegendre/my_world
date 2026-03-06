/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** load menu init
*/

#include "menu/home.h"

static
void load_btn_center(csfml_button_t *button,
    const sfRenderWindow *window, float y)
{
    sfFloatRect bounds = {0};
    sfVector2u win_size = {0};
    float x = 0.0f;

    if (!button || !window)
        return;
    sfSprite_setScale(button->sprite, (sfVector2f){1.0f, 1.0f});
    bounds = sfSprite_getGlobalBounds(button->sprite);
    win_size = sfRenderWindow_getSize((sfRenderWindow *)window);
    x = ((float)win_size.x - bounds.width) / 2.0f;
    sfSprite_setPosition(button->sprite, (sfVector2f){x, y});
}

static
void save_1_btn_cb(void *user_data)
{
    my_world_t *world_data = user_data;

    if (!world_data || !world_data->menu)
        return;
    load_map_from_legend(world_data, 1);
    csfml_menu_close(world_data->menu);
}

static
void save_2_btn_cb(void *user_data)
{
    my_world_t *world_data = user_data;

    if (!world_data || !world_data->menu)
        return;
    load_map_from_legend(world_data, 2);
    csfml_menu_close(world_data->menu);
}

static
void back_btn_cb(void *user_data)
{
    my_world_t *world_data = user_data;
    int main_page_id = -1;

    if (!world_data || !world_data->menu)
        return;
    main_page_id = world_data->main_page_id;
    if (main_page_id < 0)
        main_page_id = csfml_menu_find_page(world_data->menu, "main");
    if (main_page_id >= 0)
        csfml_menu_set_active_page(world_data->menu, main_page_id);
    csfml_menu_open(world_data->menu);
}

static void init_info(csfml_button_label_info_t *info,
    my_world_t *world_data, const char *label)
{
    info->text = label;
    info->font = world_data->font_menu;
    info->char_size = 45;
    info->color = &sfWhite;
}

static
csfml_button_t *create_load_button(my_world_t *world_data,
    const char *label, csfml_button_click_cb_t on_click, float y)
{
    sfIntRect btn_rect = {50, 455, 308, 95};
    csfml_button_t *button = NULL;
    csfml_button_label_info_t info = {0};

    if (!world_data || !world_data->menu || !world_data->tex_menu)
        return NULL;
    button = csfml_button_create(world_data->tex_menu, &btn_rect,
        on_click, world_data);
    if (!button)
        return NULL;
    init_info(&info, world_data, label);
    csfml_button_set_label(button, &info);
    apply_menu_button_sounds(world_data, button);
    load_btn_center(button, world_data->ctx->window, y);
    if (csfml_menu_add_button_to_page(world_data->menu,
            world_data->load_page_id, button) < 0) {
        csfml_button_destroy(button);
        return NULL;
    }
    return button;
}

void init_menu_load(my_world_t *world_data)
{
    if (!world_data || !world_data->menu)
        return;
    world_data->load_page_id = csfml_menu_add_page(world_data->menu, "load");
    if (world_data->load_page_id < 0)
        return;
    load_background(world_data->menu, world_data->load_page_id,
        world_data->tex_menu, world_data->ctx);
    create_load_button(world_data, "Load 1", save_1_btn_cb, 360.0f);
    create_load_button(world_data, "Load 2", save_2_btn_cb, 480.0f);
    create_load_button(world_data, "Back", back_btn_cb, 600.0f);
}

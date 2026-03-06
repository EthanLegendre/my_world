/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** exit file for my_world
*/

#include "menu/home.h"

static
void exit_btn_cb(void *user_data)
{
    my_world_t *world_data = user_data;

    if (!world_data || !world_data->ctx || !world_data->ctx->window)
        return;
    sfRenderWindow_close(world_data->ctx->window);
}

void setting_button(csfml_button_t *b_exit,
    my_world_t *world_data, csfml_button_label_info_t *info)
{
    csfml_button_set_label(b_exit, info);
    apply_menu_button_sounds(world_data, b_exit);
    sfSprite_setScale(b_exit->sprite, (sfVector2f){1.0f, 1.0f});
}

csfml_button_t *init_button_exit(my_world_t *world_data, sfTexture *menu_tex,
    sfFont *font, const sfRenderWindow *window)
{
    sfIntRect btn_rect = { .left = 50, .top = 455, .width = 308, .height = 95 };
    csfml_button_t *b_exit = csfml_button_create(menu_tex, &btn_rect,
        exit_btn_cb, world_data);
    sfFloatRect float_rect;
    sfVector2u vector2_u;
    float x_position = 0;
    csfml_button_label_info_t info = { .text = "Exit", .font = font,
        .char_size = 45, .color = &sfWhite };

    if (b_exit) {
        setting_button(b_exit, world_data, &info);
        float_rect = sfSprite_getGlobalBounds(b_exit->sprite);
        vector2_u = sfRenderWindow_getSize(window);
        x_position = ((float)vector2_u.x - float_rect.width) / 2.0f;
        sfSprite_setPosition(b_exit->sprite, (sfVector2f){x_position, 600.0f});
        csfml_menu_add_button_to_page(world_data->menu,
            world_data->main_page_id, b_exit);
    }
    return b_exit;
}

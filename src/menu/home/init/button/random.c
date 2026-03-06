/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** random file for my_world
*/

#include "menu/home.h"

// TODO: Background musique launch
static
void random_btn_cb(void *user_data)
{
    my_world_t *world_data = user_data;

    if (!world_data || !world_data->menu)
        return;
    world_data->map_seed = (unsigned int)rand();
    world_data->map_seed_dirty = 1;
    csfml_menu_close(world_data->menu);
}

static void set_pos_and_add(csfml_button_t *b_random,
    int x_position, my_world_t *world_data)
{
    sfSprite_setPosition(b_random->sprite,
        (sfVector2f){x_position, 360.0f});
    csfml_menu_add_button_to_page(world_data->menu,
        world_data->main_page_id, b_random);
}

csfml_button_t *init_button_random(my_world_t *world_data, sfTexture *menu_tex,
    sfFont *font, const sfRenderWindow *window)
{
    sfIntRect btn_rect = { 50, 455, 308, 95 };
    csfml_button_t *b_random = csfml_button_create(menu_tex, &btn_rect,
        random_btn_cb, world_data);
    sfFloatRect float_rect;
    sfVector2u vector2_u;
    float x_position = 0;
    csfml_button_label_info_t info = { .text = "Random", .font = font,
        .char_size = 45, .color = &sfWhite };

    if (b_random) {
        csfml_button_set_label(b_random, &info);
        apply_menu_button_sounds(world_data, b_random);
        sfSprite_setScale(b_random->sprite, (sfVector2f){1.0f, 1.0f});
        float_rect = sfSprite_getGlobalBounds(b_random->sprite);
        vector2_u = sfRenderWindow_getSize(window);
        x_position = ((float)vector2_u.x - float_rect.width) / 2.0f;
        set_pos_and_add(b_random, x_position, world_data);
    }
    return b_random;
}

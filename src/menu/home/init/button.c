/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** button file for my_world
*/

#include "menu/home.h"
#include "stdbool.h"

void apply_menu_button_sounds(my_world_t *world_data, csfml_button_t *button)
{
    sfSound *hover_sound = NULL;
    sfSound *click_sound = NULL;

    if (!world_data || !world_data->ctx || !button)
        return;
    hover_sound = csfml_sound_load(world_data->ctx,
        "menu_btn_hover", "assets/musique/hover.ogg");
    click_sound = csfml_sound_load(world_data->ctx,
        "menu_btn_click", "assets/musique/menu-click.ogg");
    if (hover_sound)
        csfml_button_set_hover_sound(button, hover_sound);
    if (click_sound)
        csfml_button_set_click_sound(button, click_sound);
}

bool main_menu_init_buttons(my_world_t *world_data, sfTexture *menu_tex,
    sfFont *font, const sfRenderWindow *window)
{
    if (!init_button_random(world_data, menu_tex, font, window) ||
        !init_button_load(world_data, menu_tex, font, window) ||
        !init_button_exit(world_data, menu_tex, font, window))
        return false;
    return true;
}

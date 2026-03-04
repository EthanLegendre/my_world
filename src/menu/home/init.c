/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** init file for my_world
*/

#include "menu/home.h"

void init_menu_home(my_world_t *world_data)
{
    world_data->main_page_id = csfml_menu_add_page(world_data->menu, "main");
    load_background(world_data->menu, world_data->main_page_id, world_data->tex_menu, world_data->ctx);
    main_menu_init_buttons(world_data, world_data->tex_menu, world_data->font_menu, world_data->ctx->window);
}
/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** menu file for my_world
*/

#include "menu/home.h"

void init_menu(my_world_t *world_data)
{
    world_data->menu = csfml_menu_create();
    if (!world_data->menu)
        return;
    init_menu_home(world_data);
    init_menu_load(world_data);
    init_menu_save(world_data);
    init_menu_pause(world_data);
    csfml_menu_set_active_page(world_data->menu, world_data->main_page_id);
    csfml_menu_open(world_data->menu);
    world_data->menu_open = 1;
}

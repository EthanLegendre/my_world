/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** home file for my_world
*/

#ifndef MY_WORLD_HOME_H
    #define MY_WORLD_HOME_H

    #include "my_world.h"
    #include "menu.h"
    #include "button.h"
    #include "sound.h"
    #include "init_project.h"
    #include "textures_simple.h"
    #include <stdbool.h>

void init_menu(my_world_t *world_data);
void init_menu_home(my_world_t *world_data);
void init_menu_load(my_world_t *world_data);
sfTexture *load_background(csfml_menu_t *menu, int main_page_id,
    sfTexture *tex_menu, const csfml_context_t *ctx);
csfml_button_t *init_button_random(my_world_t *world_data, sfTexture *menu_tex,
    sfFont *font, const sfRenderWindow *window);
csfml_button_t *init_button_load(my_world_t *world_data,
    sfTexture *menu_tex, sfFont *font,
    const sfRenderWindow *window);
csfml_button_t *init_button_exit(my_world_t *world_data, sfTexture *menu_tex,
    sfFont *font, const sfRenderWindow *window);
bool main_menu_init_buttons(my_world_t *world_data, sfTexture *menu_tex,
    sfFont *font, const sfRenderWindow *window);
void apply_menu_button_sounds(my_world_t *world_data, csfml_button_t *button);
void init_menu_pause(my_world_t *world_data);
#endif //MY_WORLD_HOME_H
/*
** EPITECH PROJECT, 2025
** init
** File description:
** inti
*/

#include <stdlib.h>
#include <time.h>
#include "my_world.h"
#include "textures_simple.h"

static
sfTexture *menu_load_texture(csfml_context_t *ctx)
{
    sfTexture *menu_tex = csfml_tex_load(
        ctx, "menu", "assets/menu_asset4.png");

    if (!menu_tex) {
        return NULL;
    }
    return menu_tex;
}

static my_world_t *init_word_data(csfml_context_t *ctx)
{
    my_world_t *world_data = malloc(sizeof(my_world_t));

    if (!world_data)
        return NULL;
    world_data->ctx = NULL;
    world_data->menu = NULL;
    world_data->tex_menu = menu_load_texture(ctx);
    world_data->font_menu = sfFont_createFromFile(
        "assets/font/DancingScript-Bold.ttf");
    world_data->map_seed = (unsigned int)rand();
    world_data->map_seed_dirty = 0;
    world_data->main_page_id = -1;
    world_data->load_page_id = -1;
    world_data->edit_page_id = -1;
    world_data->menu_open = 0;
    world_data->pause_page_id = -1;
    return world_data;
}

my_world_t *init(void)
{
    csfml_context_t *ctx = csfml_context_create("My world", WINDOW_SIZE_X,
        WINDOW_SIZE_Y, 120000);
    my_world_t *world_data = NULL;

    srand((unsigned int)time(NULL));
    if (!ctx)
        return NULL;
    world_data = init_word_data(ctx);
    if (!world_data)
        return NULL;
    world_data->ctx = ctx;
    sfRenderWindow_setKeyRepeatEnabled(world_data->ctx->window, sfFalse);
    return world_data;
}

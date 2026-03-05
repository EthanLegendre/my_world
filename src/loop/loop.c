/*
** EPITECH PROJECT, 2025
** game_loop
** File description:
** game_loop
*/

#include <stdlib.h>

#include "my_world.h"
#include "loop_internal.h"
#include "textures_simple.h"

static
void free_map_2d(sfVector2f **map_2d)
{
    if (!map_2d)
        return;
    for (int i = 0; i < MAP_Y; i++)
        free(map_2d[i]);
    free(map_2d);
}

static
void free_convex_array(sfConvexShape ***tab)
{
    if (!tab)
        return;
    for (int i = 0; i < MAP_Y; i++) {
        if (tab[i]) {
            for (int j = 0; j < MAP_X; j++) {
                if (tab[i][j])
                    sfConvexShape_destroy(tab[i][j]);
            }
            free(tab[i]);
        }
    }
    free(tab);
}

static
void free_runtime_resources(world_runtime_t *runtime)
{
    if (!runtime)
        return;
    free_map_2d(runtime->map_2d);
    free_convex_array(runtime->rendus_map);
    free_convex_array(runtime->rendus_map2);
    runtime->map_2d = NULL;
    runtime->rendus_map = NULL;
    runtime->rendus_map2 = NULL;
}

static
void load_world_textures(my_world_t *world_data, game_info_t *game_info)
{
    if (!world_data || !world_data->ctx || !game_info)
        return;
    game_info->water_texture = csfml_tex_load(world_data->ctx,
        "world_water", "assets/water.png");
    game_info->herbe_texture = csfml_tex_load(world_data->ctx,
        "world_grass",
        "assets/isometric tileset/separated images/tile_027.png");
    game_info->snow_texture = csfml_tex_load(world_data->ctx,
        "world_rock", "assets/rock3.png");
    game_info->sand_texture = csfml_tex_load(world_data->ctx,
        "world_sand", "assets/image.png");
}

void game_loop(my_world_t *world_data, camera_t *camera, game_info_t *game_info)
{
    world_runtime_t runtime = {0};

    if (!world_data->ctx || !world_data->ctx->window)
        return;
    runtime.init = world_data;
    runtime.camera = camera;
    runtime.game_info = game_info;
    runtime.rendus_map = create_convex_array_empty();
    runtime.rendus_map2 = NULL;
    runtime.map_2d = create_2d_map_empty(runtime.map_3d, camera);
    if (!runtime.rendus_map || !runtime.map_2d) {
        free_runtime_resources(&runtime);
        return;
    }
    if (fill_map_with_perlin(runtime.map_3d, world_data->map_seed) != 0) {
        free_runtime_resources(&runtime);
        return;
    }
    load_world_textures(world_data, game_info);
    world_data->active_camera = runtime.camera;
    world_data->active_map_2d = runtime.map_2d;
    world_data->active_rendus_dirty = &runtime.rendus_dirty;
    world_data->active_map_3d = runtime.map_3d;
    update_iso_point(runtime.map_3d, runtime.map_2d, runtime.camera);
    loop_register_input_callbacks(&runtime);
    csfml_context_run(world_data->ctx, loop_on_frame, loop_on_draw, &runtime);
    world_data->active_camera = NULL;
    world_data->active_map_2d = NULL;
    world_data->active_rendus_dirty = NULL;
    world_data->active_map_3d = NULL;
    free_runtime_resources(&runtime);
}

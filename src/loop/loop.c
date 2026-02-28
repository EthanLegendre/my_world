/*
** EPITECH PROJECT, 2025
** game_loop
** File description:
** game_loop
*/

#include "my_world.h"
#include "loop_internal.h"

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
void load_world_textures(init_t *init, game_info_t *game_info)
{
    if (!init || !init->ctx || !game_info)
        return;
    game_info->water_texture = csfml_tex_load(init->ctx,
        "world_water", "assets/water.png");
    game_info->herbe_texture = csfml_tex_load(init->ctx,
        "world_grass", "assets/isometric tileset/separated images/tile_027.png");
    game_info->snow_texture = csfml_tex_load(init->ctx,
        "world_rock", "assets/rock3.png");
    game_info->sand_texture = csfml_tex_load(init->ctx,
        "world_sand", "assets/image.png");
}

void game_loop(init_t *init, camera_t *camera, game_info_t *game_info)
{
    world_runtime_t runtime = {0};
    int **noise = noise_perlin(MAP_X, MAP_Y);

    if (!init || !init->ctx || !init->window)
        return;
    runtime.init = init;
    runtime.camera = camera;
    runtime.game_info = game_info;
    runtime.rendus_map = create_convex_array_empty();
    runtime.rendus_map2 = NULL;
    runtime.map_2d = create_2d_map_empty(runtime.map_3d, camera);
    if (!runtime.rendus_map || !runtime.map_2d) {
        free_runtime_resources(&runtime);
        if (noise) {
            for (int i = 0; i < MAP_Y; i++)
                free(noise[i]);
            free(noise);
        }
        return;
    }
    load_world_textures(init, game_info);
    if (noise) {
        for (int i = 0; i < MAP_Y; i++) {
            for (int j = 0; j < MAP_X; j++)
                runtime.map_3d[i][j] = (noise[i][j] * HAUTEUR_MAX) / 255;
            free(noise[i]);
        }
        free(noise);
    }
    update_iso_point(runtime.map_3d, runtime.map_2d, runtime.camera);
    csfml_context_set_key_press_cb(init->ctx, loop_on_key_pressed);
    csfml_context_run(init->ctx, loop_on_frame, loop_on_draw, &runtime);
    free_runtime_resources(&runtime);
}

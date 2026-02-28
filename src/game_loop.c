/*
** EPITECH PROJECT, 2025
** game_loop
** File description:
** game_loop
*/

#include "../include/my_world.h"

void game_loop(init_t *init, camera_t *camera, game_info_t *game_info)
{
    int map_3d[MAP_Y][MAP_X] = {0};
    sfConvexShape ***rendus_map = create_convex_array_empty();
    sfConvexShape ***rendus_map2 = create_convex_array_empty();
    sfVector2f **map_2d = create_2d_map_empty(MAP_Y, MAP_X);
    int **noise = noise_perlin(MAP_X, MAP_Y);

    if (noise) {
        for (int i = 0; i < MAP_Y; i++) {
            for (int j = 0; j < MAP_X; j++)
                map_3d[i][j] = (noise[i][j] * HAUTEUR_MAX) / 255;
            free(noise[i]);
        }
        free(noise);
    }
    while (sfRenderWindow_isOpen(init->window)) {
        while (sfRenderWindow_pollEvent(init->window, &init->event))
            manage_event(init, game_info);
        sfRenderWindow_clear(init->window, sfBlack);
        if (game_info->edit_mode){
            manage_edit_mode(map_3d, map_2d, camera, game_info);
            draw_edit_map(init->window, map_2d, map_3d);
        } else {
            manage_rendus_mode(rendus_map, rendus_map2,map_3d, map_2d, camera);
            draw_rendus_map(init->window, map_2d, map_3d, rendus_map);
        }
        sfRenderWindow_display(init->window);
    }
}

void manage_event(init_t *init, game_info_t *game_info)
{
    if ((init->event).type == sfEvtClosed)
        sfRenderWindow_close(init->window);
    if (init->event.type == sfEvtKeyPressed)
        if (init->event.key.code == sfKeyEscape)
            sfRenderWindow_close(init->window);
    if (init->event.type == sfEvtKeyPressed)
        if (sfKeyboard_isKeyPressed(sfKeyV)){
            game_info->edit_mode = !game_info->edit_mode;
            printf("%d\n", game_info->edit_mode);
        }
}

/*
** EPITECH PROJECT, 2026
** manage_elect_point
** File description:
** manage_select_point
*/

#include "../../../include/my_world.h"

static void change_z_upper(int *tab, int *tab2,
    game_info_t *gi, int map_3d[MAP_Y][MAP_Y])
{
    int y = tab[0] + tab2[0];
    int x = tab[1] + tab2[1];

    if (y >= 0 && y < MAP_Y && x >= 0 && x < MAP_X)
        map_3d[y][x] += gi->weight;
}

static void change_z_lower(int *tab, int *tab2,
    game_info_t *gi, int map_3d[MAP_Y][MAP_Y])
{
    int y = tab[0] + tab2[0];
    int x = tab[1] + tab2[1];

    if (y >= 0 && y < MAP_Y && x >= 0 && x < MAP_X)
        map_3d[y][x] -= gi->weight;
}

void update_upper_aroud_point(int *tab,
    game_info_t *gi, int *add, int map_3d[MAP_Y][MAP_X])
{
    int tab2[2];
    int origin[2] = {tab[0] - (gi->weight / 2), tab[1] - (gi->weight / 2)};

    for (int k = 0; k <= gi->weight; k++) {
        for (int l = 0; l <= gi->weight; l++) {
            tab2[0] = k;
            tab2[1] = l;
            change_z_upper(origin, tab2, gi, map_3d);
        }
    }
}

void update_lower_aroud_point(int *tab,
    game_info_t *gi, int *add, int map_3d[MAP_Y][MAP_X])
{
    int tab2[2];
    int origin[2] = {tab[0] - (gi->weight / 2), tab[1] - (gi->weight / 2)};

    for (int k = 0; k <= gi->weight; k++) {
        for (int l = 0; l <= gi->weight; l++) {
            tab2[0] = k;
            tab2[1] = l;
            change_z_lower(origin, tab2, gi, map_3d);
        }
    }
}

void change_z_by_select_point(int map_3d[MAP_Y][MAP_X],
    game_info_t *game_info, int *int_tab, sfVector2f *current_point)
{
    int add = 0;

    if (ABS(current_point->x - game_info->mouse_pos.x) < 10
        && ABS(current_point->y - game_info->mouse_pos.y) < 10){
        if (game_info->up){
            update_upper_aroud_point(int_tab, game_info, &add, map_3d);
            map_3d[int_tab[0]][int_tab[1]] += 20;
        } else {
            map_3d[int_tab[0]][int_tab[1]] -= 20;
            update_lower_aroud_point(int_tab, game_info, &add, map_3d);
        }
    }
}

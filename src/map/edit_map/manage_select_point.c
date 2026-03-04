/*
** EPITECH PROJECT, 2026
** manage_elect_point
** File description:
** manage_select_point
*/

#include "../../../include/my_world.h"


void update_aroud_point(int i, int j, int *add, int map_3d[MAP_Y][MAP_X])
{
    for (int k = 1; k <= 5; k++){
        *add = 5 / k;
        if (i + k < MAP_Y)
            map_3d[i + k][j] += *add;
        if (j + k < MAP_X)
            map_3d[i][j + k] += *add;
        if (i - k >= 0)
            map_3d[i - k][j] += *add;
        if (j - k >= 0)
            map_3d[i][j - k] += *add;
    }
}

void change_z_by_select_point(int map_3d[MAP_Y][MAP_X],
    sfVector2i *mouse_pos, int *int_tab, sfVector2f *current_point)
{
    int add = 0;

    if (ABS(current_point->x - mouse_pos->x) < 10
        && ABS(current_point->y - mouse_pos->y) < 10){
        map_3d[int_tab[0]][int_tab[1]] += 20;
        update_aroud_point(int_tab[0], int_tab[1], &add, map_3d);
    }
}

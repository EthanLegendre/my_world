/*
** EPITECH PROJECT, 2026
** manage_elect_point
** File description:
** manage_select_point
*/

#include "../../../include/my_world.h"

void change_z_by_select_point(int map_3d[MAP_Y][MAP_X], sfVector2i mouse_pos, int i, int j, sfVector2f current_point)
{
    if (ABS(current_point.x - mouse_pos.x) < 10
    && ABS(current_point.y - mouse_pos.y) < 10){
        map_3d[i][j] += 20;
        for (int k = 1; k < 30; k++){
            map_3d[i + k][j] += 5 / k;
            map_3d[i][j + k] += 5 / k;
            map_3d[i - k][j] += 5 / k;
            map_3d[i][j - k] += 5 / k;
            }
    }
}

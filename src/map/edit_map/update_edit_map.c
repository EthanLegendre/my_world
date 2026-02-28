/*
** EPITECH PROJECT, 2026
** manage_edit_map
** File description:
** manage_edit_map
*/

#include "../../../include/my_world.h"

#ifndef PI_F
    #define PI_F 3.14159265358979323846f
#endif

void update_iso_point(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d, camera_t *camera)
{
    float angle_x = camera->angle_x * PI_F / 180.f;
    float angle_y = camera->angle_y * PI_F / 180.f;
    float cos_x = cosf(angle_x);
    float sin_x = sinf(angle_x);
    float cos_y = cosf(angle_y);
    float sin_y = sinf(angle_y);
    float cx = (MAP_X - 1) * SPACE / 2.f;
    float cy = (MAP_Y - 1) * SPACE / 2.f;
    float center_x = WINDOW_SIZE_X / 2.f + camera->x;
    float center_y = WINDOW_SIZE_Y / 2.f + camera->y;
    float zoom = camera->zoom;
    float x = 0.0f;
    float y = 0.0f;
    float rel_x = 0.0f;
    float rel_y = 0.0f;
    float z = 0.0f;
    float screen_x = 0.0f;
    float screen_y = 0.0f;

    for (int i = 0; i < MAP_Y; i++) {
        y = (float)(SPACE * i);
        for (int j = 0; j < MAP_X; j++) {
            x = (float)(SPACE * j);
            rel_x = x - cx;
            rel_y = y - cy;
            z = (float)map_3d[i][j];
            screen_x = (cos_x * rel_x - sin_x * rel_y) * zoom + center_x;
            screen_y = (cos_y * (sin_x * rel_x + cos_x * rel_y)
                - sin_y * z) * zoom + center_y;
            map_2d[i][j] = (sfVector2f){screen_x, screen_y};
        }
    }
}

void update_edit_map(int map_3d[MAP_Y][MAP_X], sfVector2i mouse_pos, camera_t *camera)
{
    sfVector2f current_point;

    for (int i = 0; i< MAP_Y; i++){
        for (int j = 0; j < MAP_X; j++){
            current_point = project_iso_point(SPACE * j, SPACE * i, map_3d[i][j], camera);
            change_z_by_select_point(map_3d, mouse_pos, i, j, current_point);
        }
    }
}
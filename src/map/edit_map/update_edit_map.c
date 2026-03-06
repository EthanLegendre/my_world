/*
** EPITECH PROJECT, 2026
** manage_edit_map
** File description:
** manage_edit_map
*/

#include "../../../include/my_world.h"

ip_t *init_struct(camera_t *camera)
{
    ip_t *ip = malloc(sizeof(ip_t));

    ip->angle_x = camera->angle_x * PI_F / 180.f;
    ip->angle_y = camera->angle_y * PI_F / 180.f;
    ip->cos_x = cosf(ip->angle_x);
    ip->sin_x = sinf(ip->angle_x);
    ip->cos_y = cosf(ip->angle_y);
    ip->sin_y = sinf(ip->angle_y);
    ip->cx = (MAP_X - 1) * SPACE / 2.f;
    ip->cy = (MAP_Y - 1) * SPACE / 2.f;
    ip->center_x = WINDOW_SIZE_X / 2.f + camera->x;
    ip->center_y = WINDOW_SIZE_Y / 2.f + camera->y;
    ip->zoom = camera->zoom;
    ip->x = 0.0f;
    ip->y = 0.0f;
    ip->rel_x = 0.0f;
    ip->rel_y = 0.0f;
    ip->screen_x = 0.0f;
    ip->screen_y = 0.0f;
    return ip;
}

void update_iso_point(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d,
    camera_t *camera)
{
    ip_t *ip = init_struct(camera);

    ip->z = 0.0f;
    for (int i = 0; i < MAP_Y; i++) {
        ip->y = (float)(SPACE * i);
        for (int j = 0; j < MAP_X; j++) {
            ip->x = (float)(SPACE * j);
            ip->rel_x = ip->x - ip->cx;
            ip->rel_y = ip->y - ip->cy;
            ip->z = (float)map_3d[i][j];
            ip->screen_x = (ip->cos_x * ip->rel_x - ip->sin_x * ip->rel_y)
                * ip->zoom + ip->center_x;
            ip->screen_y = (ip->cos_y * (ip->sin_x * ip->rel_x +
                    ip->cos_x * ip->rel_y)
                - ip->sin_y * ip->z) * ip->zoom + ip->center_y;
            map_2d[i][j] = (sfVector2f){ip->screen_x, ip->screen_y};
        }
    }
    free(ip);
}

void update_edit_map(int map_3d[MAP_Y][MAP_X], game_info_t *game_info,
    camera_t *camera)
{
    sfVector2f current_point;
    int *tab_int = malloc(sizeof(int) * 2);

    for (int i = 0; i < MAP_Y; i++){
        for (int j = 0; j < MAP_X; j++){
            tab_int[0] = i;
            tab_int[1] = j;
            current_point = project_iso_point(SPACE * j, SPACE * i,
                map_3d[i][j], camera);
            change_z_by_select_point(map_3d, game_info,
                tab_int, &current_point);
        }
    }
}

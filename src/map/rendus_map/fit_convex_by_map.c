/*
** EPITECH PROJECT, 2026
** fit_convex_by_map
** File description:
** fix_convex_by_map
*/

#include "../../../include/my_world.h"

#ifndef PI_F
    #define PI_F 3.14159265358979323846f
#endif

static
int snap_height(int z)
{
    int rem = z % SPACE;

    if (rem == 0)
        return z;
    return z + (SPACE - rem);
}

static
sfTexture *get_texture_for_height(int z, game_info_t *game_info)
{
    if (!game_info)
        return NULL;
    if (z < 3000)
        return game_info->water_texture;
    if (z <= 3100)
        return game_info->sand_texture;
    if (z <= 4000)
        return game_info->herbe_texture;
    if (z <= 5000)
        return game_info->snow_texture;
    return NULL;
}

static
sfVector2f project_iso_fast(float x, float y, float z,
    const camera_t *camera, float cos_x, float sin_x, float cos_y,
    float sin_y, float cx, float cy, float center_x, float center_y,
    float zoom)
{
    float rel_x = x - cx;
    float rel_y = y - cy;
    float screen_x = (cos_x * rel_x - sin_x * rel_y) * zoom + center_x;
    float screen_y = (cos_y * (sin_x * rel_x + cos_x * rel_y) - sin_y * z)
        * zoom + center_y;

    (void)camera;
    return (sfVector2f){screen_x, screen_y};
}

void fit_convex_by_map(sfConvexShape ***tab,
    int map_3d[MAP_Y][MAP_X], camera_t *camera, game_info_t *game_info)
{
    sfTexture *current_texture = NULL;
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
    int z = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            z = snap_height(map_3d[i][j]);
            x = SPACE * j;
            y = SPACE * i;
            sfConvexShape_setPoint(tab[i][j], 0,
                project_iso_fast((float)x, (float)y, (float)z, camera,
                    cos_x, sin_x, cos_y, sin_y, cx, cy,
                    center_x, center_y, zoom));
            sfConvexShape_setPoint(tab[i][j], 1,
                project_iso_fast((float)(x + SPACE), (float)y, (float)z,
                    camera, cos_x, sin_x, cos_y, sin_y, cx, cy,
                    center_x, center_y, zoom));
            sfConvexShape_setPoint(tab[i][j], 2,
                project_iso_fast((float)(x + SPACE), (float)(y + SPACE),
                    (float)z, camera, cos_x, sin_x, cos_y, sin_y, cx, cy,
                    center_x, center_y, zoom));
            sfConvexShape_setPoint(tab[i][j], 3,
                project_iso_fast((float)x, (float)(y + SPACE), (float)z,
                    camera, cos_x, sin_x, cos_y, sin_y, cx, cy,
                    center_x, center_y, zoom));
            current_texture = get_texture_for_height(z, game_info);
            if (current_texture) {
                sfConvexShape_setTexture(tab[i][j], current_texture, sfFalse);
                sfConvexShape_setFillColor(tab[i][j], sfWhite);
            } else {
                sfConvexShape_setTexture(tab[i][j], NULL, sfFalse);
                sfConvexShape_setFillColor(tab[i][j],
                    change_color_by_z(z));
            }
        }
    }
}

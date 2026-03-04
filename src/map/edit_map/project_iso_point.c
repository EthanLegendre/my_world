/*
** EPITECH PROJECT, 2026
** project_iso_point
** File description:
** project_iso_point
*/

#include "../../../include/my_world.h"
#include <math.h>

static
float deg_to_rad(float deg)
{
    return deg * PI_F / 180.f;
}

sfVector2f project_iso_point(int x, int y, int z, camera_t *camera)
{
    const float cx = (MAP_X - 1) * SPACE / 2.f;
    const float cy = (MAP_Y - 1) * SPACE / 2.f;
    float X = (float)x - cx;
    float Y = (float)y - cy;
    float Z = (float)z;
    float cos_x = cosf(deg_to_rad(camera->angle_x));
    float sin_x = sinf(deg_to_rad(camera->angle_x));
    float cos_y = cosf(deg_to_rad(camera->angle_y));
    float sin_y = sinf(deg_to_rad(camera->angle_y));
    float screen_x = cos_x * X - sin_x * Y;
    float screen_y = cos_y * (sin_x * X + cos_x * Y) - sin_y * Z;

    screen_x *= camera->zoom;
    screen_y *= camera->zoom;
    screen_x += WINDOW_SIZE_X / 2.f + camera->x;
    screen_y += WINDOW_SIZE_Y / 2.f + camera->y;
    return (sfVector2f){screen_x, screen_y};
}

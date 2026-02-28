/*
** EPITECH PROJECT, 2026
** project_iso_point
** File description:
** project_iso_point
*/

#include "../../../include/my_world.h"
#include <math.h>

static inline float deg_to_rad(float deg)
{
    return deg * (float)M_PI / 180.f;
}

sfVector2f project_iso_point(int x, int y, int z, camera_t *camera)
{
    float ax   = deg_to_rad(camera->angle_x);
    float ay = deg_to_rad(camera->angle_y);
    float cx = (MAP_X - 1) * SPACE / 2.f;
    float cy = (MAP_Y - 1) * SPACE / 2.f;
    float X = (float)x - cx;
    float Y = (float)y - cy;
    float Z = (float)z;
    float x1 =  cosf(ax) * X - sinf(ax) * Y;
    float y1 =  sinf(ax) * X + cosf(ax) * Y;
    float z1 =  Z;
    float x2 = x1;
    float y2 =  cosf(ay) * y1 - sinf(ay) * z1;
    float z2 =  sinf(ay) * y1 + cosf(ay) * z1;
    float screen_x = x2;
    float screen_y = y2;
    sfVector2u size = (sfVector2u){1920u, 1080u};

    screen_x *= camera->zoom;
    screen_y *= camera->zoom;
    screen_x += size.x / 2.f + camera->x;
    screen_y += size.y / 2.f + camera->y;

    return (sfVector2f){screen_x, screen_y};
}
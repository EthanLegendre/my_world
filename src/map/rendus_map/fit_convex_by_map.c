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
sfVector2f project_iso_fast(fcbm_t *fcbm, camera_t *camera)
{
    float rel_x = fcbm->x - fcbm->cx;
    float rel_y = fcbm->y - fcbm->cy;
    float screen_x = (fcbm->cos_x * rel_x - fcbm->sin_x * rel_y)
        * fcbm->zoom + fcbm->center_x;
    float screen_y = (fcbm->cos_y * (fcbm->sin_x * rel_x +
            fcbm->cos_x * rel_y) - fcbm->sin_y * fcbm->z)
        * fcbm->zoom + fcbm->center_y;

    return (sfVector2f){screen_x, screen_y};
}

fcbm_t *init_fcbm(camera_t *camera)
{
    fcbm_t *fcbm = malloc(sizeof(fcbm_t));

    fcbm->angle_x = camera->angle_x * PI_F / 180.f;
    fcbm->angle_y = camera->angle_y * PI_F / 180.f;
    fcbm->cos_x = cosf(fcbm->angle_x);
    fcbm->sin_x = sinf(fcbm->angle_x);
    fcbm->cos_y = cosf(fcbm->angle_y);
    fcbm->sin_y = sinf(fcbm->angle_y);
    fcbm->cx = (MAP_X - 1) * SPACE / 2.f;
    fcbm->cy = (MAP_Y - 1) * SPACE / 2.f;
    fcbm->center_x = WINDOW_SIZE_X / 2.f + camera->x;
    fcbm->center_y = WINDOW_SIZE_Y / 2.f + camera->y;
    fcbm->zoom = camera->zoom;
    fcbm->z = 0;
    fcbm->x = 0;
    fcbm->y = 0;
    return fcbm;
}

void set_point(sfConvexShape ***tab, fcbm_t *fcbm,
    camera_t *camera, int *tab_int)
{
    sfConvexShape_setPoint(tab[tab_int[0]][tab_int[1]], 0,
        project_iso_fast(fcbm, camera));
    fcbm->x += SPACE;
    sfConvexShape_setPoint(tab[tab_int[0]][tab_int[1]], 1,
        project_iso_fast(fcbm, camera));
    fcbm->y += SPACE;
    sfConvexShape_setPoint(tab[tab_int[0]][tab_int[1]], 2,
        project_iso_fast(fcbm, camera));
    fcbm->x -= SPACE;
    sfConvexShape_setPoint(tab[tab_int[0]][tab_int[1]], 3,
        project_iso_fast(fcbm, camera));
}

void set_good_texture(sfConvexShape ***tab,
    fcbm_t *fcbm, int *tab_int, sfTexture *current_texture)
{
    if (current_texture) {
        sfConvexShape_setTexture(tab[tab_int[0]][tab_int[1]],
            current_texture, sfFalse);
        sfConvexShape_setFillColor(tab[tab_int[0]][tab_int[1]], sfWhite);
    } else {
        sfConvexShape_setTexture(tab[tab_int[0]][tab_int[1]], NULL, sfFalse);
        sfConvexShape_setFillColor(tab[tab_int[0]][tab_int[1]],
            change_color_by_z(fcbm->z));
    }
}

void fit_convex_by_map(sfConvexShape ***tab,
    int map_3d[MAP_Y][MAP_X], camera_t *camera, game_info_t *game_info)
{
    sfTexture *current_texture = NULL;
    fcbm_t *fcbm = init_fcbm(camera);
    int *tab_int = malloc(sizeof(int) * 2);

    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            tab_int[0] = i;
            tab_int[1] = j;
            fcbm->z = snap_height(map_3d[i][j]);
            fcbm->x = SPACE * j;
            fcbm->y = SPACE * i;
            set_point(tab, fcbm, camera, tab_int);
            set_good_texture(tab, fcbm, tab_int, current_texture);
            current_texture = get_texture_for_height(fcbm->z, game_info);
        }
    }
}

/*
** EPITECH PROJECT, 2026
** fit_convex_by_map
** File description:
** fix_convex_by_map
*/

#include "../../../include/my_world.h"

void fit_convex_by_map(sfConvexShape ***tab, sfVector2f **map_2d, int map_3d[MAP_Y][MAP_X], camera_t *camera)
{
    sfTexture *water_texture = sfTexture_createFromFile("assets/water.png", NULL);
    sfTexture *herbe_texture = sfTexture_createFromFile("assets/isometric tileset/separated images/tile_027.png", NULL);
    sfTexture *rock_texture = sfTexture_createFromFile("assets/rock3.png", NULL);


    for (int i = 0; i < MAP_Y; i++){
        for (int j = 0; j < MAP_X; j++){
            if (map_3d[i][j] % SPACE != 0)
                map_3d[i][j] += SPACE - (map_3d[i][j] % SPACE);
        }
    }
    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            sfConvexShape_setPoint(tab[i][j], 0, project_iso_point(SPACE * j, SPACE * i, map_3d[i][j], camera));
            sfConvexShape_setPoint(tab[i][j], 1, project_iso_point(SPACE * (j + 1), SPACE * i, map_3d[i][j], camera));
            sfConvexShape_setPoint(tab[i][j], 2, project_iso_point(SPACE * (j + 1), SPACE * (i + 1), map_3d[i][j], camera));
            sfConvexShape_setPoint(tab[i][j], 3, project_iso_point(SPACE * j, SPACE * (i + 1), map_3d[i][j], camera));
            sfConvexShape_setFillColor(tab[i][j], change_color_by_z(map_3d[i][j]));
            /*if (map_3d[i][j] < 3000)
                sfConvexShape_setTexture(tab[i][j], water_texture, sfFalse);
            else if (map_3d[i][j] >= 3100 && map_3d[i][j] <= 4000)
                sfConvexShape_setTexture(tab[i][j], herbe_texture, sfFalse);
            else if (map_3d[i][j] <= 5000 && map_3d[i][j] >= 4000)
                sfConvexShape_setTexture(tab[i][j], rock_texture, sfFalse);
            else*/
            sfConvexShape_setFillColor(tab[i][j], change_color_by_z(map_3d[i][j]));
        }
    }
}

void fit_convex_by_map2(sfConvexShape ***tab, int map_3d[MAP_Y][MAP_X], camera_t *camera)
{
    for (int i = 0; i < MAP_Y; i++){
        for (int j = 0; j < MAP_X; j++){
            if (map_3d[i][j] % SPACE != 0)
                map_3d[i][j] += SPACE - (map_3d[i][j] % SPACE);
        }
    }
    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            sfConvexShape_setPoint(tab[i][j], 0, project_iso_point(SPACE * (j + 1), SPACE * (i + 1), map_3d[i][j], camera));
            sfConvexShape_setPoint(tab[i][j], 1, project_iso_point(SPACE * (j + 1), SPACE * i, map_3d[i][j], camera));
            sfConvexShape_setPoint(tab[i][j], 2, project_iso_point(SPACE * j, SPACE * i, map_3d[i][j + 1], camera));
            sfConvexShape_setPoint(tab[i][j], 3, project_iso_point(SPACE * j, SPACE * (i + 1), map_3d[i][j + 1], camera));
            sfConvexShape_setFillColor(tab[i][j], change_color_by_z(map_3d[i][j]));
        }
    }
}
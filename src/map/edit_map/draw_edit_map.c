/*
** EPITECH PROJECT, 2026
** draw_edit_map
** File description:
** draw_edit_map
*/

#include "../../../include/my_world.h"

static void draw_all_line_in_x(sfRenderWindow *window, sfVector2f **map_2d, int i, int map_3d[MAP_Y][MAP_X])
{
    sfVertexArray *line;

    for (int j = 0; j < MAP_X; j++) {
        if (j + 1 < MAP_X) {
            line = create_line_by_two_points(&map_2d[i][j], &map_2d[i][j + 1], map_3d[i][j+1]);
            sfRenderWindow_drawVertexArray(window, line, NULL);
            sfVertexArray_destroy(line);
        }
        if (i + 1 < MAP_Y) {
            line = create_line_by_two_points(&map_2d[i][j], &map_2d[i + 1][j], map_3d[i + 1][j]);
            sfRenderWindow_drawVertexArray(window, line, NULL);
            sfVertexArray_destroy(line);
        }
    }
}

int draw_edit_map(sfRenderWindow *window, sfVector2f **map_2d, int map_3d[MAP_Y][MAP_X])
{
    for (int i = 0; i < MAP_Y; i++)
        draw_all_line_in_x(window, map_2d, i, map_3d);
    return 0;
}
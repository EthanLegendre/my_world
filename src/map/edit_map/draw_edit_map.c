/*
** EPITECH PROJECT, 2026
** draw_edit_map
** File description:
** draw_edit_map
*/

#include "../../../include/my_world.h"

static void append_segment(sfVertexArray *lines, sfVector2f *a,
    sfVector2f *b, int z)
{
    sfVertex vertices[2];
    sfColor color = change_color_by_z(z);

    vertices[0] = (sfVertex){.position = *a, .color = color};
    vertices[1] = (sfVertex){.position = *b, .color = color};
    sfVertexArray_append(lines, vertices[0]);
    sfVertexArray_append(lines, vertices[1]);
}

static void append_all_line_in_x(sfVertexArray *lines, sfVector2f **map_2d,
    int i, int map_3d[MAP_Y][MAP_X])
{
    for (int j = 0; j < MAP_X - 1; j++)
        append_segment(lines, &map_2d[i][j], &map_2d[i][j + 1],
            map_3d[i][j + 1]);
    if (i + 1 >= MAP_Y)
        return;
    for (int j = 0; j < MAP_X; j++)
        append_segment(lines, &map_2d[i][j], &map_2d[i + 1][j],
            map_3d[i + 1][j]);
}

int draw_edit_map(sfRenderWindow *window, sfVector2f **map_2d,
    int map_3d[MAP_Y][MAP_X])
{
    sfVertexArray *lines = sfVertexArray_create();

    if (!lines)
        return 84;
    sfVertexArray_setPrimitiveType(lines, sfLines);
    for (int i = 0; i < MAP_Y; i++)
        append_all_line_in_x(lines, map_2d, i, map_3d);
    sfRenderWindow_drawVertexArray(window, lines, NULL);
    sfVertexArray_destroy(lines);
    return 0;
}

/*
** EPITECH PROJECT, 2026
** create_line_by_two_points
** File description:
** create_line_by_two_points
*/

#include "../../../include/my_world.h"

sfVertexArray *create_line_by_two_points(sfVector2f *point1 , sfVector2f *point2, int z)
{
    int ht_max = HAUTEUR_MAX;
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor color = change_color_by_z(z);
    sfVertex vertex1 = {.position = *point1, .color = color};
    sfVertex vertex2 = {.position = *point2, .color = color};

    sfVertexArray_append(vertex_array , vertex1);
    sfVertexArray_append(vertex_array , vertex2);
    sfVertexArray_setPrimitiveType(vertex_array , sfLinesStrip);
    return vertex_array;
}
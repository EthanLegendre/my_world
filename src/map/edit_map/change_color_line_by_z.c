/*
** EPITECH PROJECT, 2026
** change_color_line_by_z
** File description:
** change_color_line_by_z
*/

#include "../../../include/my_world.h"

sfColor change_color_by_z(int z)
{
    if (z < 3000)
        return (sfColor){0, 0, 255, 255};
    if (z <= 3100 && z >= 3000)
        return (sfColor){254, 234, 84, 255};
    if (z > 5000)
        return (sfColor){255, 255, 255, 255};
    if (z <= 5000 && z >= 4000)
        return (sfColor){150, 150, 150, 255};
    return (sfColor){20, 190, 0, 255};
}

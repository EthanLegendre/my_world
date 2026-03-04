/*
** EPITECH PROJECT, 2026
** draw_rendus_map
** File description:
** draw_rendus_map
*/

#include "../../../include/my_world.h"

static
int intersects_view(sfFloatRect *a, sfFloatRect *b)
{
    if (a->left + a->width < b->left)
        return 0;
    if (b->left + b->width < a->left)
        return 0;
    if (a->top + a->height < b->top)
        return 0;
    if (b->top + b->height < a->top)
        return 0;
    return 1;
}

static
void draw_convex(sfRenderWindow *window, int i, sfConvexShape ***tab,
    sfFloatRect *view_rect)
{
    sfFloatRect shape_bounds;

    for (int j = 0; j < MAP_X - 1; j++) {
        if (!tab[i][j])
            continue;
        shape_bounds = sfConvexShape_getGlobalBounds(tab[i][j]);
        if (intersects_view(&shape_bounds, view_rect))
            sfRenderWindow_drawConvexShape(window, tab[i][j], NULL);
    }
}

int draw_rendus_map(sfRenderWindow *window, sfConvexShape ***convex_tab)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfFloatRect view_rect = {0.0f, 0.0f, (float)win_size.x,
        (float)win_size.y};

    if (!window || !convex_tab)
        return 84;
    for (int i = 0; i < MAP_Y - 1; i++)
        draw_convex(window, i, convex_tab, &view_rect);
    return 0;
}

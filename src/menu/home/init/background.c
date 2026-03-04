/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** background file for my_world
*/

#include "menu.h"
#include "init_project.h"

static
void main_menu_scale_and_center(
    sfSprite *bg, const sfRenderWindow *window)
{
    sfVector2u position = {0, 0};
    sfFloatRect b = {0};
    float max_h = 0.0f;
    float base_scale = 1.0f;
    float x = 0.0f;
    float y = 0.0f;

    if (!bg || !window)
        return;
    position = sfRenderWindow_getSize((sfRenderWindow *)window);
    b = sfSprite_getGlobalBounds(bg);
    max_h = (float)position.y * 0.7f;
    if (b.height > max_h)
        base_scale = max_h / b.height;
    sfSprite_setScale(bg, (sfVector2f){base_scale, base_scale * 1.5f});
    b = sfSprite_getGlobalBounds(bg);
    x = ((float)position.x - b.width) / 2.0f;
    y = ((float)position.y - b.height) / 2.0f;
    sfSprite_setPosition(bg, (sfVector2f){x, y});
}

sfTexture *load_background(csfml_menu_t *menu, int main_page_id,
    sfTexture *tex_menu, const csfml_context_t *ctx)
{
    sfIntRect panel_rect = { .left = 485, .top = 20,
        .width = 465, .height = 400 };

    csfml_menu_set_page_background_rect(menu, main_page_id,
        tex_menu, &panel_rect);
    main_menu_scale_and_center(menu->pages[main_page_id].background, ctx->window);
}

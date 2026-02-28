/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector label helpers
*/

#include "../../includes/selector.h"
#include <SFML/Graphics.h>

static void selector_set_label_color(
    csfml_selector_t *selector, const sfColor *color)
{
    if (color) {
        selector->label_color = *color;
        sfText_setFillColor(selector->label, *color);
    } else {
        selector->label_color = (sfColor){255, 255, 255, 255};
        sfText_setFillColor(selector->label, selector->label_color);
    }
}

int csfml_selector_set_label(csfml_selector_t *selector,
    const csfml_selector_label_info_t *info)
{
    if (!selector || !info || !info->text)
        return 0;
    if (!selector->label) {
        selector->label = sfText_create();
        if (!selector->label)
            return 0;
    }
    selector->label_font = info->font;
    if (info->font)
        sfText_setFont(selector->label, info->font);
    sfText_setString(selector->label, info->text);
    selector->label_char_size = info->char_size;
    sfText_setCharacterSize(selector->label, info->char_size);
    selector_set_label_color(selector, info->color);
    return 1;
}

int csfml_selector_set_label_info(csfml_selector_t *selector,
    const csfml_selector_label_info_t *info)
{
    return csfml_selector_set_label(selector, info);
}

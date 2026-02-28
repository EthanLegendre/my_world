/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** selector helper functions split out
*/

#include "../../includes/selector.h"

void csfml_selector_set_padding(csfml_selector_t *sel, float pad)
{
    if (!sel)
        return;
    sel->padding = pad;
}

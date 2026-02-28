/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** extra button setters split out to keep file limits
*/

#include "button.h"
#include <SFML/Audio.h>

void csfml_button_set_click_sound(csfml_button_t *btn, sfSound *sound)
{
    if (!btn)
        return;
    btn->click_sound = sound;
}

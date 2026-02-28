/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_play
*/

#include "sound.h"

void csfml_sound_play(sfSound *sound)
{
    if (!sound)
        return;
    sfSound_play(sound);
}

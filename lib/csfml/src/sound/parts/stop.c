/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_stop
*/

#include "sound.h"

void csfml_sound_stop(sfSound *sound)
{
    if (!sound)
        return;
    sfSound_stop(sound);
}

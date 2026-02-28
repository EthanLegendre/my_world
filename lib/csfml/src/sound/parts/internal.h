/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** sound internal helpers
*/

#ifndef CSFML_SOUND_INTERNAL_H
    #define CSFML_SOUND_INTERNAL_H

    #include "sound.h"

char *csfml_strdup_safe(const char *s);
sound_node_t **csfml_sounds_head(csfml_context_t *ctx);
sound_node_t *csfml_sound_node_create(csfml_context_t *ctx, const char *key,
    sfSoundBuffer *buf, sfSound *s);
void csfml_sound_node_free(sound_node_t *n);

#endif

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_get
*/

#include "sound.h"
#include "internal.h"
#include "my.h"

sfSound *csfml_sound_get(csfml_context_t *ctx, const char *key)
{
    if (!ctx || !key)
        return NULL;
    for (sound_node_t *n = *csfml_sounds_head(ctx); n; n = n->next) {
        if (my_strcmp(n->key, key) == 0)
            return n->sound;
    }
    return NULL;
}

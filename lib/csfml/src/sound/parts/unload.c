/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_unload
*/

#include "sound.h"
#include "internal.h"
#include "my.h"

void csfml_sound_unload(csfml_context_t *ctx, const char *key)
{
    sound_node_t **pp = NULL;
    sound_node_t *n = NULL;

    if (!ctx || !key)
        return;
    pp = csfml_sounds_head(ctx);
    while (*pp) {
        n = *pp;
        if (my_strcmp(n->key, key) == 0) {
            *pp = n->next;
            csfml_sound_node_free(n);
            return;
        }
        pp = &n->next;
    }
}

/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_cleanup
*/

#include "sound.h"
#include "internal.h"

void csfml_sound_cleanup(csfml_context_t *ctx)
{
    sound_node_t *n = *csfml_sounds_head(ctx);
    sound_node_t *next = NULL;

    if (!ctx)
        return;
    while (n) {
        next = n->next;
        csfml_sound_node_free(n);
        n = next;
    }
    *csfml_sounds_head(ctx) = NULL;
}

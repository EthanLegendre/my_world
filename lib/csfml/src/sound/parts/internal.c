/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** sound internal helpers implementation
*/

#include "internal.h"
#include "my.h"
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../../../includes/init_project.h"

char *csfml_strdup_safe(const char *s)
{
    if (!s)
        return NULL;
    return my_strdup(s);
}

sound_node_t **csfml_sounds_head(csfml_context_t *ctx)
{
    if (!ctx)
        return NULL;
    return &ctx->sounds_head;
}

sound_node_t *csfml_sound_node_create(csfml_context_t *ctx, const char *key,
    sfSoundBuffer *buf, sfSound *s)
{
    sound_node_t *n = malloc(sizeof(*n));

    if (!n)
        return NULL;
    n->key = csfml_strdup_safe(key);
    if (!n->key) {
        free(n);
        return NULL;
    }
    n->buffer = buf;
    n->sound = s;
    n->next = *csfml_sounds_head(ctx);
    *csfml_sounds_head(ctx) = n;
    return n;
}

void csfml_sound_node_free(sound_node_t *n)
{
    if (!n)
        return;
    if (n->sound)
        sfSound_destroy(n->sound);
    if (n->buffer)
        sfSoundBuffer_destroy(n->buffer);
    free(n->key);
    free(n);
}

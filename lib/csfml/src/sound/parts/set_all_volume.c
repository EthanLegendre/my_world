/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_set_all_volume
*/

#include "sound.h"
#include "internal.h"
#include "my.h"


void csfml_sound_set_all_volume(csfml_context_t *ctx, float volume)
{
    sound_node_t *n;

    if (!ctx)
        return;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    for (n = *csfml_sounds_head(ctx); n; n = n->next) {
        if (n->sound)
            sfSound_setVolume(n->sound, volume);
    }
}

static int sound_node_matches_keys(const char *node_key,
    const char **keys, size_t n)
{
    size_t i;

    if (!node_key || !keys)
        return 0;
    for (i = 0; i < n; ++i) {
        if (!keys[i])
            continue;
        if (my_strcmp(node_key, keys[i]) == 0)
            return 1;
    }
    return 0;
}

void csfml_sound_set_volume_for_keys(csfml_context_t *ctx,
    const char **keys, size_t n, float volume)
{
    sound_node_t *node = NULL;

    if (!ctx || !keys || n == 0)
        return;
    if (volume < 0.0f)
        volume = 0.0f;
    if (volume > 100.0f)
        volume = 100.0f;
    for (node = *csfml_sounds_head(ctx); node; node = node->next) {
        if (!node->sound)
            continue;
        if (!node->key)
            continue;
        if (sound_node_matches_keys(node->key, keys, n))
            sfSound_setVolume(node->sound, volume);
    }
}

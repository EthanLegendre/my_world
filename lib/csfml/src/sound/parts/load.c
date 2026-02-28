/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** csfml_sound_load
*/

#include "sound.h"
#include "internal.h"
#include "my.h"
#include <SFML/Audio.h>
#include <stdlib.h>


static sfSound *csfml_sound_create_and_register(csfml_context_t *ctx,
    const char *key, sfSoundBuffer *buf)
{
    sfSound *s = sfSound_create();

    if (!s)
        return NULL;
    sfSound_setBuffer(s, buf);
    if (!csfml_sound_node_create(ctx, key, buf, s)) {
        sfSound_destroy(s);
        return NULL;
    }
    return s;
}

sfSound *csfml_sound_load(csfml_context_t *ctx, const char *key,
    const char *file_path)
{
    sfSound *existing = NULL;
    sfSoundBuffer *buf = NULL;
    sfSound *s = NULL;

    if (!ctx || !key || !file_path)
        return NULL;
    existing = csfml_sound_get(ctx, key);
    if (existing)
        return existing;
    buf = sfSoundBuffer_createFromFile(file_path);
    if (!buf)
        return NULL;
    s = csfml_sound_create_and_register(ctx, key, buf);
    if (!s) {
        sfSoundBuffer_destroy(buf);
        return NULL;
    }
    return s;
}

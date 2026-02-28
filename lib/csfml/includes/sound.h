/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** simple sound manager
*/

#ifndef CSFML_SOUND_H
    #define CSFML_SOUND_H

    #include <stddef.h>
    #include <SFML/Audio.h>

typedef struct csfml_context csfml_context_t;

typedef struct sound_node {
    char *key;
    sfSoundBuffer *buffer;
    sfSound *sound;
    struct sound_node *next;
} sound_node_t;

sfSound *csfml_sound_load(csfml_context_t *ctx, const char *key,
    const char *file_path);
sfSound *csfml_sound_get(csfml_context_t *ctx, const char *key);
void csfml_sound_play(sfSound *sound);
void csfml_sound_stop(sfSound *sound);
void csfml_sound_unload(csfml_context_t *ctx, const char *key);
void csfml_sound_cleanup(csfml_context_t *ctx);
void csfml_sound_set_all_volume(csfml_context_t *ctx, float volume);
void csfml_sound_set_volume_for_keys(csfml_context_t *ctx,
    const char **keys, size_t n, float volume);

#endif

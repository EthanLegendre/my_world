/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** lib_csfml_textures_generate
*/

#ifndef CSFML_TEXTURES_H
    #define CSFML_TEXTURES_H

    #include <SFML/Graphics.h>
    #include <stddef.h>

typedef struct csfml_texture {
    sfTexture *handle;
    char *path;
    unsigned int width;
    unsigned int height;
    unsigned int reference_count;
    unsigned int animation_frame_count;
    unsigned int animation_frame_index;
} csfml_texture_t;
typedef struct csfml_texture_entry {
    char *key;
    csfml_texture_t *texture;
} csfml_texture_entry_t;
typedef struct csfml_texture_manager {
    csfml_texture_entry_t *entries;
    size_t count;
    size_t capacity;
} csfml_texture_manager_t;

csfml_texture_manager_t *csfml_texture_manager_create(size_t initial_capacity);
void csfml_texture_manager_destroy(csfml_texture_manager_t *manager);
csfml_texture_t *csfml_texture_manager_load(csfml_texture_manager_t *manager,
    const char *key, const char *file_path);
csfml_texture_t *csfml_texture_manager_get(csfml_texture_manager_t *manager,
    const char *key);
void csfml_texture_manager_unload(csfml_texture_manager_t *manager,
    const char *key);
csfml_texture_t *csfml_texture_create_from_file(const char *file_path);
void csfml_texture_destroy(csfml_texture_t *texture);
void csfml_texture_set_animation_frames(csfml_texture_t *texture,
    unsigned int frame_count);
void csfml_texture_set_frame_index(csfml_texture_t *texture,
    unsigned int frame_index);
unsigned int csfml_texture_advance_frame(csfml_texture_t *texture);
sfIntRect csfml_texture_get_frame_rect(const csfml_texture_t *texture,
    unsigned int frame_index);
sfIntRect csfml_texture_get_current_frame_rect(const csfml_texture_t *texture);

#endif

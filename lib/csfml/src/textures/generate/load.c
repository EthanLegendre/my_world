/*
** EPITECH PROJECT, 2025
** csfml_lib
** File description:
** load texture into manager
*/

#include "../../../includes/textures.h"
#include <stdlib.h>
#include <string.h>

int csfml_texture_manager_ensure_capacity(csfml_texture_manager_t *m);

csfml_texture_t *csfml_texture_manager_load(csfml_texture_manager_t *manager,
    const char *key, const char *file_path)
{
    csfml_texture_t *existing = NULL;
    csfml_texture_t *tex = NULL;
    char *kdup = NULL;

    if (!manager || !key || !file_path) return NULL;
    existing = csfml_texture_manager_get(manager, key);
    if (existing) {
        existing->reference_count++;
        return existing;
    }
    if (csfml_texture_manager_ensure_capacity(manager) != 0) return NULL;
    csfml_texture_create_from_file(file_path);
    if (!tex) return NULL;
    kdup = my_strdup(key);
    if (!kdup) { csfml_texture_destroy(tex); return NULL; }
    manager->entries[manager->count].key = kdup;
    manager->entries[manager->count].texture = tex;
    manager->count++;
    return tex;
}

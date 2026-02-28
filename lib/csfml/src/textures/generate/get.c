/*
** EPITECH PROJECT, 2025
** csfml_lib
** File description:
** lookup functions
*/

#include "../../../includes/textures.h"
#include <string.h>
#include "libs/my.h"

csfml_texture_t *csfml_texture_manager_get(csfml_texture_manager_t *manager,
    const char *key)
{
    if (!manager || !key) return NULL;
    for (size_t i = 0; i < manager->count; ++i) {
        if (manager->entries[i].key && my_strcmp(manager->entries[i].key, key) == 0)
            return manager->entries[i].texture;
    }
    return NULL;
}

/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** Cursor helper header
*/

#include "../../../includes/textures.h"
#include "my.h"
#include <string.h>
#include <stdlib.h>

void csfml_texture_manager_unload(csfml_texture_manager_t *manager,
    const char *key)
{
    if (!manager || !key) return;
    for (size_t i = 0; i < manager->count; ++i) {
        if (manager->entries[i].key && my_strcmp(manager->entries[i].key, key) == 0) {
            csfml_texture_t *t = manager->entries[i].texture;
            if (t) {
                if (t->reference_count > 1) {
                    t->reference_count--;
                } else {
                    csfml_texture_destroy(t);
                    free(manager->entries[i].key);
                    for (size_t j = i + 1; j < manager->count; ++j)
                        manager->entries[j - 1] = manager->entries[j];
                    manager->count--;
                }
            }
            return;
        }
    }
}

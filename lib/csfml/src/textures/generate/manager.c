/*
** EPITECH PROJECT, 2025
** csfml_lib
** File description:
** texture manager allocation/growth/destruction
*/

#include "../../../includes/textures.h"
#include <stdlib.h>

#define DEFAULT_INITIAL_CAPACITY 16

static
int manager_grow_if_needed(csfml_texture_manager_t *m)
{
    size_t newcap = 0;
    csfml_texture_entry_t *n = NULL;

    if (m->count < m->capacity)
        return 0;
    newcap = (m->capacity == 0) ? DEFAULT_INITIAL_CAPACITY : m->capacity * 2;
    n = malloc(newcap * sizeof(*n));
    if (!n)
        return -1;
    if (m->entries && m->capacity > 0) {
        for (size_t i = 0; i < m->capacity; ++i)
            n[i] = m->entries[i];
    }
    for (size_t i = m->capacity; i < newcap; ++i) {
        n[i].texture = NULL;
        n[i].key = NULL;
    }
    free(m->entries);
    m->entries = n;
    m->capacity = newcap;
    return 0;
}

csfml_texture_manager_t *csfml_texture_manager_create(size_t initial_capacity)
{
    csfml_texture_manager_t *m = malloc(sizeof(*m));

    if (!m)
        return NULL;
    if (initial_capacity == 0)
        initial_capacity = DEFAULT_INITIAL_CAPACITY;
    m->entries = malloc(initial_capacity * sizeof(*m->entries));
    if (!m->entries) {
        free(m);
        return NULL;
    }
    for (size_t i = 0; i < initial_capacity; ++i) {
        m->entries[i].texture = NULL;
        m->entries[i].key = NULL;
    }
    m->count = 0;
    m->capacity = initial_capacity;
    return m;
}

void csfml_texture_manager_destroy(csfml_texture_manager_t *manager)
{
    if (!manager)
        return;

    for (size_t i = 0; i < manager->count; ++i) {
        if (manager->entries[i].texture)
            csfml_texture_destroy(manager->entries[i].texture);
        free(manager->entries[i].key);
    }
    free(manager->entries);
    free(manager);
}

int csfml_texture_manager_ensure_capacity(csfml_texture_manager_t *m)
{
    return manager_grow_if_needed(m);
}
